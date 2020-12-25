from matplotlib import pyplot as plt
import numpy as np
import pandas as pd

from pylab import *
mpl.rcParams['font.sans-serif'] = ['SimHei']

section = [0, 35, 75, 115, 150, 250, 99999]
section_name = ["优", "良", "轻度污染", "中度污染", "重度污染", "严重污染"]

orig_df = pd.read_csv("./BeijingPM20100101_20151231.csv", encoding='utf-8', dtype=str)
orig_df = pd.DataFrame(orig_df, columns=['year', 'month', 'day', 'PM_US Post'])
df = orig_df.dropna(0, how='any')

df['PM_US Post'] = df['PM_US Post'].astype(np.int)

result = pd.DataFrame(pd.cut(df['PM_US Post'], section, labels=section_name, ordered=False))
result_count = result['PM_US Post'].value_counts(sort=False)

plt.pie(result_count, labels=result_count.index, startangle=90, counterclock=False, radius=1.5, textprops={'fontsize':8}, labeldistance=0.5)
plt.show()