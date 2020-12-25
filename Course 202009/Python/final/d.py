import pandas as pd
import numpy as np
from matplotlib import pyplot as plt
from pylab import *
mpl.rcParams['font.sans-serif'] = ['SimHei']

fileNameStr = './20201215.csv'  # 读取最后一天的疫情数据
df = pd.read_csv(fileNameStr, encoding='utf-8')
population = pd.read_csv('./population.csv', encoding='utf-8')  # 读取世界人口数据

df['total'] = df['total'].astype(np.int)
df['percent'] = None  # 新增一列用于存储确诊比例

for i in range(len(df)):  # 从人口数据中若找到该国家则计算比例
    if not population[population['country'].isin([df['country'][i]])]['population'].empty:
        df['percent'][i] = int(df['total'][i]) / int(population[population['country'].isin([df['country'][i]])]['population'])

df.sort_values('percent', inplace=True, ascending=False)  # 按照确诊比例降序排序
df = df.reset_index(drop=True)  # 重置序号

country = []
percent = []

plt.title("20201215 新冠病毒确诊人数比例国家TOP10")
for i in range(10):  # 记录前10的国家名称和确诊比例
    country.append(df['country'][i])
    percent.append(df['percent'][i])
plt.bar(country, percent, label='percent')
plt.legend()
plt.show()