import numpy as np
import matplotlib.pyplot as plt
import math
from mpl_toolkits.mplot3d import Axes3D

#1.生成fig对象和ax对象
fig = plt.figure()
ax = fig.add_subplot(projection='3d')
ax.set_xlabel('X Label')
ax.set_ylabel('Y Label')
ax.set_zlabel('Z Label')

#2.生成数据
x = np.array([1,0,2,1,2,2,1,2,0,1,0,0])
y = np.array([1,0,0,1,0,2,1,2,2,1,2,0])
z = np.array([1,0,0,1,0,0,1,0,0,1,0,0])
z_minus = -1 * z;

#3.调用plot，画3D的线图
ax.plot(x,y,z_minus,"b",marker='o')
ax.plot(x,y,z,"r",marker='o')

#4.显示图形
plt.show()
