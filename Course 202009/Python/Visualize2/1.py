from matplotlib import pyplot as plt
import numpy as np
import pandas as pd

from pylab import *
mpl.rcParams['font.sans-serif'] = ['SimHei']

df = pd.read_csv("./iris.csv", encoding='utf-8', dtype=str)
df = pd.DataFrame(df, columns=['Sepal.length', 'Sepal.width', 'Petal.Length', 'Petal.Width', 'Species'], dtype=str)

colors = ['blue', 'orange', 'green']

df['Sepal.length'] = df['Sepal.length'].astype(np.float)
df['Sepal.width'] = df['Sepal.width'].astype(np.float)
df['Petal.Length'] = df['Petal.Length'].astype(np.float)
df['Petal.Width'] = df['Petal.Width'].astype(np.float)

Species = df.Species.unique()
print(Species)

fig, ax = plt.subplots()

labelx = ['Petal.Width', 'Petal.Length', 'Sepal.width', 'Sepal.length']
labely = ['Sepal.length', 'Sepal.width', 'Petal.Length', 'Petal.Width']

for index in range(16):
    plt.subplot(4, 4, index + 1)
    plt.xlabel(labelx[index % 4])
    plt.ylabel(labely[int(index / 4)])
    plt.title(labelx[index % 4] + ' vs ' + labely[int(index / 4)])
    plt.grid(True, linestyle='--', alpha=0.8)
    for i in range(len(Species)):
        plt.scatter(df.loc[df.Species == Species[i], labelx[index % 4]], df.loc[df.Species == Species[i], labely[int(index / 4)]], s=5, color=colors[i], label=Species[i])


plt.subplots_adjust(left=None, bottom=None, right=None, top=None,
                wspace=1, hspace=1)
plt.show()