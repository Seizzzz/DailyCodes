from matplotlib import pyplot as plt
import numpy as np
import pandas as pd

from pylab import *
mpl.rcParams['font.sans-serif'] = ['SimHei']

section = [0, 35, 75, 115, 150, 250, 99999]
section_name = ["优", "良", "轻度污染", "中度污染", "重度污染", "严重污染"]
labels = ['北京', '成都', '广州', '上海', '沈阳']

def classify(s):
    fileNameStr = s
    orig_df = pd.read_csv(fileNameStr, encoding='utf-8', dtype=str)
    orig_df = pd.DataFrame(orig_df, columns=['year', 'month', 'day', 'PM_US Post'])
    df = orig_df.dropna(0, how='any')

    df['PM_US Post'] = df['PM_US Post'].astype(int)

    result = pd.cut(df['PM_US Post'], section, labels=section_name, ordered=False)
    # print(result)
    return pd.DataFrame(pd.value_counts(result, sort=False))


data_bj = classify('./BeijingPM20100101_20151231.csv')
print(data_bj.describe())
data_cd = classify('./ChengduPM20100101_20151231.csv')
data_gz = classify('./GuangzhouPM20100101_20151231.csv')
data_sh = classify('./ShanghaiPM20100101_20151231.csv')
data_sy = classify('./ShenyangPM20100101_20151231.csv')

x = np.arange(len(section_name))
width = 0.1
fig, ax = plt.subplots(figsize=(8, 4))
rects1 = ax.bar(x-2*width, np.array(data_bj['PM_US Post']), width, label='bj')
rects2 = ax.bar(x-width, np.array(data_cd['PM_US Post']), width, label='cd')
rects3 = ax.bar(x, np.array(data_gz['PM_US Post']), width, label='gz')
rects4 = ax.bar(x+width, np.array(data_sh['PM_US Post']), width, label='sh')
rects5 = ax.bar(x+2*width, np.array(data_sy['PM_US Post']), width, label='sy')
plt.xticks(range(0, 6), section_name)

plt.show()