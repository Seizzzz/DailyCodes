import pandas as pd
import numpy as np
from matplotlib import pyplot as plt
from pylab import *
mpl.rcParams['font.sans-serif'] = ['SimHei']

fileNameStr = './20201215.csv'  # 读取最后一天的疫情数据
df = pd.read_csv(fileNameStr, encoding='utf-8')

df['total'] = df['total'].astype(np.int)
df.sort_values('total', inplace=True, ascending=False)  # 按照确诊总数降序排序
df = df.reset_index(drop=True)  # 重置序号

country = []
total = []
remain = 73294020  # 由题a获取的15日的世界确诊总数

for i in range(9):  # 记录前10的国家名称和确诊总数
    country.append(df['country'][i])
    total.append(df['total'][i])
    remain = remain - int(df['total'][i])

country.append('其他国家') # 加入其他国家数据
total.append(remain)

plt.title("20201215 新冠病毒确诊人数国家饼图")
plt.pie(total, labels=country, autopct='%1.1f%%')
plt.show()