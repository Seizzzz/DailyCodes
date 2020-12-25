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
x = []
y = []
z = [i + 1 for i in range(25)]

left = up = -1
down = right = 5
px = py = 0
x.append(px)
y.append(py)

def add(px, py):
    x.append(px)
    y.append(py)

while True:
    if px == 2 and py == 2:
        break
    while py + 1 < down:
        py = py + 1
        add(px, py)
    left = left + 1
    while px + 1 < right:
        px = px + 1
        add(px, py)
    down = down - 1
    while py - 1 > up:
        py = py - 1
        add(px, py)
    right = right - 1
    while px - 1 > left:
        px = px - 1
        add(px, py)
    up = up + 1

bottom = [0 for _ in range(25)]
width = depth = 0.5

#3.调用bar3d，画3D直方图
ax.bar3d(x, y, bottom, width, depth, z, shade=True)

#4.显示图形
plt.show()
