from matplotlib import pyplot as plt
import numpy as np
import pandas as pd

from pylab import *
mpl.rcParams['font.sans-serif'] = ['SimHei']

# import random
#
# semester1 = np.arange(1, 11)
# semester2 = np.arange(1, 11)
# semester3 = np.arange(1, 11)
#
# random.shuffle(semester1)
# random.shuffle(semester2)
# random.shuffle(semester3)
#
# df = pd.DataFrame({'semester1':semester1, 'semester2':semester2, 'semester3':semester3})
# print(df)
#
# df.to_csv("data1403.csv", encoding="utf-8")

df = pd.read_csv("./data1403.csv", encoding='utf-8', dtype=str)
df = pd.DataFrame(df, columns=['semester1', 'semester2', 'semester3'], dtype=np.int)

df['total'] = (df['semester1'] + df['semester2'] + df['semester3']) / 3
df = df.sort_values('total')

fig, ax = plt.subplots()
plt.style.use('classic')
plt.title('RANK')

width = 0.2
x = np.array(range(0, 10))
rect1 = ax.bar(x-2*width, df['semester1'], width=width, label='semester1')
rect2 = ax.bar(x-width, df['semester2'], width=width, label='semester2')
rect3 = ax.bar(x, df['semester3'], width=width, label='semester3')

for r in rect1:
    ax.text(r.get_x(), r.get_height(), r.get_height())
for r in rect2:
    ax.text(r.get_x(), r.get_height(), r.get_height())
for r in rect3:
    ax.text(r.get_x(), r.get_height(), r.get_height())

plt.legend(ncol=1)
plt.show()