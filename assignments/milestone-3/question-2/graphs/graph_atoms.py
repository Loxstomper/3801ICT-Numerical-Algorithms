import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import sys

x = []
y = []
z = []

for line in sys.stdin:
    a, b, c = line.split()
    x.append(float(a))
    y.append(float(b))
    z.append(float(c))

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

ax.scatter(x, y, z)

plt.show()


