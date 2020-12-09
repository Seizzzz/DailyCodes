import pandas as pd
from sklearn.preprocessing import StandardScaler
import matplotlib.pyplot as plt

fileNameStr = './result-handled.csv'
df = pd.read_csv(fileNameStr, encoding='utf-8')

# print(df.head())
# print(df.describe())
# print(df.info())

total_min = df['totalPrice'].mean()
total_std = df['totalPrice'].std()
total_range_min = total_min - 3 * total_std
total_range_max = total_min + 3 * total_std

newdf = df[df['totalPrice'] <= total_range_max]
newdf = newdf[newdf['totalPrice'] >= total_range_min]

print(newdf.append(df).drop_duplicates(keep=False))

df = newdf

section = [0, 90, 144, 99999]
labels = ['小户型', '中户型', '大户型']
df['totalPrice'] = df['totalPrice'].astype(int)
df['evenPrice'] = df['evenPrice'].astype(int)
df['cal'] = df['totalPrice'] * 10000 / df['evenPrice']

df['sizetype'] = pd.cut(df['cal'], section, labels=labels, ordered=False)
df = df.sort_values(by=['sizetype', 'cal'])

print(df)

df.to_csv("result-classified.csv", encoding="utf-8")

#生成fig对象和ax对象
fig = plt.figure()
#ax1 = fig.add_subplot(111)
ax1 = fig.add_subplot(231)

#子图1：原始图像
x1 = df["evenPrice"] # PRES_new2
y1 = df["totalPrice"]
ax1.scatter(x1, y1, s=10)
#ax1.set_xlim(0,1250)
#ax1.set_ylim(0,1250)
ax1.set_xlabel("even")
ax1.set_ylabel("total")
ax1.set_title("Original")
print(type(x1))


#子图2:(0,1)归一化，采用MinMaxScaler函数
ax2 = fig.add_subplot(232)

min=x1.min()
max=x1.max()
ave=x1.mean()
std=x1.std()
x2=(x1-min)/(max-min)

from sklearn.preprocessing import MinMaxScaler
scaler = MinMaxScaler()
y_reshape = y1.values.reshape(-1, 1) #变成n行1列的二维矩阵形式
y2 = scaler.fit_transform(y_reshape) #调用MinMaxScaler的fit_transform转换方法，进行归一化处理

ax2.scatter(x2, y2, s=10)
ax2.set_title("MinMaxScaler")

#子图3:Z-score归一化，采用StandardScaler函数
ax3 = fig.add_subplot(233)

scaler_std = StandardScaler()
x_reshape = x1.values.reshape(-1, 1)
x3 = scaler_std.fit_transform(x_reshape)

y_reshape = y1.values.reshape(-1, 1)
y3 = scaler_std.fit_transform(y_reshape)

ax3.scatter(x3, y3, s=10)
ax3.set_title("StandardScaler")

#查看单个特征，在归一化之后的分布有何变化。
ax4 = fig.add_subplot(234)
ax5 = fig.add_subplot(235)
ax6 = fig.add_subplot(236)
ax4.set_title("Orig")
ax5.set_title("MinMax")
ax6.set_title("Standard")
def count_elements(scores): #定义转换函数，统计每个数值对应多少个
    scorescount = {}  #定义一个字典对象
    for i in scores:
        scorescount[int(i)] = scorescount.get(int(i), 0) + 1 #累加每个分数值的人数
    return scorescount

def count_elements1(scores): #定义转换函数，统计每个数值对应多少个
    scorescount = {}  #定义一个字典对象
    for i in scores:
        scorescount[int(i*100)] = scorescount.get(int(i*100), 0) + 1 #累加每个分数值的人数
    return scorescount

counted1 = count_elements(y1)   #可以改为y1,2,3，看看湿度的分布情况
counted2 = count_elements1(y2)   #0,1
counted3 = count_elements1(y3)   #standard

ax4.bar(counted1.keys(),counted1.values(),0.8,alpha=0.5,color='r')
ax5.bar(counted2.keys(),counted2.values(),0.8,alpha=0.5,color='r')
ax6.bar(counted3.keys(),counted3.values(),0.8,alpha=0.5,color='r')

#显示图形
plt.show()