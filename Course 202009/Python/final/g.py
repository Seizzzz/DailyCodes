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

for i in range(10):  # 记录前10的国家名称和确诊总数
    country.append(df['country'][i])
    total.append(df['total'][i])

plt.title("20201215 新冠病毒确诊人数国家箱型图")
plt.boxplot(df['total'], labels=['total'], showmeans=True)
plt.show()