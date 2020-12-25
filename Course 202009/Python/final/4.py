import pandas as pd
import numpy as np
from matplotlib import pyplot as plt
from sklearn import datasets, linear_model
from pylab import *
mpl.rcParams['font.sans-serif'] = ['SimHei']

total = []  # 记录确诊变化总数
date = [i for i in range(1, 16)]  # 记录日期序号

for i in range(1, 16):
    fileNameStr = './202012' + str(i).zfill(2) + '.csv'  # 产生文件名进行读取
    df = pd.read_csv(fileNameStr, encoding='utf-8')

    df['total'] = df['total'].astype(np.int)
    total.append(df['total'].sum())  # 计算所有国家的确诊总数

total = np.array(total)
date = np.array(date)
ptotal = total[:10].reshape((10, 1))  # 截取前10个确诊人数进行预测
pdate = date[:10].reshape((10, 1))  # 截取前10个日期进行预测

model = linear_model.LinearRegression()
model.fit(pdate, ptotal)  # 使用线性模型进行拟合

predict = model.predict(date[10:].reshape(5, 1))  # 预测后5个日期的确诊人数
predict = predict.flatten().tolist()

plt.title("1日至10日预测11日至15日 新冠病毒世界确诊人数总和")
plt.xticks(date)
plt.scatter(date, total, label='actual')  # 绘制15天的实际确诊人数
plt.scatter(date[10:], predict, label='predict')  # 绘制后5天的预测确诊人数
plt.legend()
plt.show()