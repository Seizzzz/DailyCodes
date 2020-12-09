import numpy as np
from matplotlib import pyplot as plt

x = np.linspace(-5 * np.pi, 5 * np.pi, 500)
y1 = 3 * np.cos(x)
y2 = np.sin(4*x)

fig, ax = plt.subplots()
plt.style.use('classic')

ax.spines["right"].set_visible(False)
ax.spines["top"].set_visible(False)
ax.spines['bottom'].set_position(('data',0))
ax.xaxis.set_ticks_position('bottom')
ax.spines['left'].set_position(('data',0))
ax.yaxis.set_ticks_position('left')

plt.plot(x, y1, color='blue', linestyle='-', label='y=3cosx')
plt.plot(x, y2, color='red', linestyle='-', label='y=sin3x')

plt.legend()
plt.show()