import numpy as np
import matplotlib.pyplot as plt
import random
import math
from mpl_toolkits.mplot3d import Axes3D

#1.生成fig对象和ax对象
fig = plt.figure()
ax = fig.add_subplot(projection='3d')
ax.set_xlabel('X Label')
ax.set_ylabel('Y Label')
ax.set_zlabel('Z Label')

#2.生成数据
x = np.linspace(-100,100,10000)
np.random.shuffle(x)
y = np.linspace(-100,100,10000)
np.random.shuffle(y)
z = x**2 + y**2 - 20000
z_minus = -1 * z
ax.scatter(x, y, z, zdir='z', s=1, c='r', marker='.', depthshade=True)
ax.scatter(x, y, z_minus, zdir='z', s=1, c='b', marker='.', depthshade=True)

#4.显示图形
plt.show()
