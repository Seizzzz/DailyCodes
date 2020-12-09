from matplotlib import pyplot as plt
import numpy as np

fig, ax = plt.subplots()
plt.style.use('classic')
plt.title("square numbers")

ax.set_xlim(-11, 11)
ax.set_ylim(0, 100)

x = np.array(range(-10, 11))
y = x * x
rect1 = plt.bar(x, y)

for r in rect1:
    ax.text(r.get_x(), r.get_height() / 2, r.get_height())

plt.show()