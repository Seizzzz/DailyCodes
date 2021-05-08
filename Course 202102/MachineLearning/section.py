import numpy as np
import pandas as pd
from math import log2

from sklearn.datasets import load_iris


class TreeNode:
    def __init__(self):
        self.leftChild = None
        self.rightChild = None

    def insertLeft(self, newNode):
        self.leftChild = newNode

    def insertRight(self, newNode):
        self.rightChild = newNode

    def getRightChild(self):
        return self.rightChild

    def getLeftChild(self):
        return self.leftChild


# 决策树根节点
root = TreeNode()

# 数据预处理
iris = load_iris()

data = pd.DataFrame(iris['data'])
data[4] = iris['target']

# 采样原始数据集
data: pd.DataFrame = data.sample(frac=1.0)
data.columns = ["data1", "data2", "data3", "data4", "target"]

# 按3:1比例生成训练集、测试集
split = int(150 * 0.75)
data_train: pd.DataFrame = data.iloc[0: split, :]
data_train = data_train.reset_index(drop=True)
data_test: pd.DataFrame = data.iloc[split: 150, :]
data_test = data_test.reset_index(drop=True)

# 保存训练集、测试集
# data_train.to_csv('train.csv')
# data_test.to_csv('test.csv')

# 读取训练集
data_train = pd.read_csv("train.csv", encoding='utf-8', index_col=0, header=0)


# 计算信息熵
def ent(sect):
    cnt0 = 0
    cnt1 = 0
    cnt2 = 0
    for index, row in sect.iterrows():
        kind = row["target"]
        if kind == 0.0:
            cnt0 = cnt0 + 1
        elif kind == 1.0:
            cnt1 = cnt1 + 1
        else:
            cnt2 = cnt2 + 1

    sum = cnt0 + cnt1 + cnt2
    p1 = cnt0 / sum
    p2 = cnt1 / sum
    p3 = cnt2 / sum

    ret = 0
    if p1 != 0:
        ret = ret - p1*log2(p1)
    if p2 != 0:
        ret = ret - p2*log2(p2)
    if p3 != 0:
        ret = ret - p3*log2(p3)

    return ret


# 计算当前属性二分侯选的信息增益值
def gain(secta, sectb, data):
    totalrow = len(secta) + len(sectb)
    positive = (len(secta)/totalrow)*ent(secta)
    negative = (len(sectb)/totalrow)*ent(sectb)
    return ent(data)-positive-negative


# 判断当前数据集是否只包含一种类型，即分类完毕
def is_decided(data):
    val = data["target"].iloc(0)[0]
    for index, row in data.iterrows():
        if row["target"] != val:
            return False
    return True


# 构建决策树
def decide(data, node):
    # 计算对于当前数据集的每一个属性值的最佳二分点
    maxpos = [0, 0, 0, 0]  # 保存二分点的位置
    maxgain = [-1, -1, -1, -1]  # 保存对应的信息增益值
    for col in range(1, 5):
        colname = 'data' + ('%d' % col)
        tmp = data.sort_values(colname)

        row = len(tmp)
        for i in range(1, row):
            val = gain(tmp[0:i], tmp[i:row], tmp)
            if val > maxgain[col-1]:
                maxgain[col-1] = val
                maxpos[col-1] = i

    # 选取信息增益值最大的候选点划分数据集，并保存该划分方法至决策树中
    maxval = max(maxgain)
    for i in range(4):
        if maxgain[i] == maxval:
            colname = 'data' + ('%d' % (i+1))
            tmp = tmp.sort_values(colname)  # 按能取得最大增益的属性值重新排序
            judgestd = (tmp[colname].iloc(0)[maxpos[i]] + tmp[colname].iloc(0)[maxpos[i] -1]) / 2  # 取划分点处两数均值进行划分

            # print("data%d ? %f" % (i+1, judgestd))
            node.type = 1
            node.column = colname
            node.value = judgestd

            # 前半集合
            left = tmp[:maxpos[i]]
            if is_decided(left):  # 如果当前集合已经分类完毕，插入至决策树中
                # print("data%d < %f: %d" % (i + 1, judgestd, left["target"].iloc(0)[0]))
                child = TreeNode()
                child.type = 2
                child.value = left["target"].iloc(0)[0]
                node.insertLeft(child)
            else:  # 对前半集合继续生成决策树
                # print("data%d < %f, " % (i + 1, judgestd), end='')
                child = TreeNode()
                node.insertLeft(child)
                decide(tmp[:maxpos[i]], node.getLeftChild())

            # 后半集合
            right = tmp[maxpos[i]:]
            if is_decided(right):  # 如果当前集合已经分类完毕，插入至决策树中
                # print("data%d > %f: %d" % (i + 1, judgestd, right["target"].iloc(0)[0]))
                child = TreeNode()
                child.type = 2
                child.value = right["target"].iloc(0)[0]
                node.insertRight(child)
            else:  # 对后半集合继续生成决策树
                # print("data%d > %f, " % (i + 1, judgestd), end='')
                child = TreeNode()
                node.insertRight(child)
                decide(tmp[maxpos[i]:], node.getRightChild())

            break


# 打印决策树
def dfs_print(node, depth):
    if node.type == 1:  #type=1表示待比较的决策节点
        print("比较%s属性值: %f" % (node.column, node.value))
    elif node.type == 2:  # type=2表示可返回决策结果的叶结点
        print("判断该样本为: %d类型" % (node.value))

    if node.getLeftChild() != None:
        for _ in range(depth+1):
            print("    ", end='')
        print("若小于, 则", end='')
        dfs_print(node.getLeftChild(), depth+1)
    if node.getRightChild() != None:
        for _ in range(depth+1):
            print("    ", end='')
        print("若大于, 则", end='')
        dfs_print(node.getRightChild(), depth+1)


# 对某一条数据应用决策树进行决策
def judge(root, row):
    now = root
    while now.type != 2:
        if row[now.column] < now.value:
            now = now.getLeftChild()
        else:
            now = now.getRightChild()
    return now.value


# 对测试集应用决策树进行决策
def test(root, sect):
    correct = 0
    for index, row in sect.iterrows():
        res = judge(root, row)
        # print(row)
        # print("result=%f, expect=%f" % (res, row["target"]))
        if res == row["target"]:
            correct = correct + 1
    print("决策树的准确率: %d/%d(%f)" % (correct, len(sect), correct/len(sect)))
    return correct/len(sect)


# 通过测试集预剪枝
def try_cut(root, node, sect):
    # 如果已经是叶结点，不需要剪枝
    if node.type == 2:
        return

    # 备份当前的决策节点
    sv_node = TreeNode()
    sv_node.leftChild = node.leftChild
    sv_node.rightChild = node.rightChild
    sv_node.type = node.type
    sv_node.column = node.column
    sv_node.value = node.value

    # 测试当前对于测试集的决策准确率
    ori_correct = test(root, sect)
    # 将当前决策节点依次转换为所有鸢尾花类型的叶结点
    for classtype in range(1,4):
        node.type = 2
        node.value = float(classtype)
        node.insertLeft(None)
        node.insertRight(None)
        now_correct = test(root, sect)  # 测试转换后的决策准确率
        if now_correct < ori_correct:  # 当前准确率小于原先准确率，恢复原决策节点
            node.leftChild = sv_node.leftChild
            node.rightChild = sv_node.rightChild
            node.type = sv_node.type
            node.column = sv_node.column
            node.value = sv_node.value

    # 继续递归其余子节点
    if node.getLeftChild() != None:
        try_cut(root, node.getLeftChild(), sect)
    if node.getRightChild() != None:
        try_cut(root, node.getRightChild(), sect)

# main
# 生成决策树
decide(data_train, root)

# 打印当前决策树, 读取测试集并输出当前决策树对测试集的准确率
print("------------------------------")
dfs_print(root, 0)
data_test = pd.read_csv("test.csv", encoding='utf-8', index_col=0, header=0)
test(root, data_test)
print("------------------------------")

# 尝试剪枝
try_cut(root, root, data_test)
# 打印剪枝后的决策树
print("------------------------------")
dfs_print(root, 0)
test(root, data_test)
print("------------------------------")


