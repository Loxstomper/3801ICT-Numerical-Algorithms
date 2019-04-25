import math
import matplotlib.pyplot as plt
import numpy as np

def f(theta, V0, Y0):
    GRAVITY = 9.81
    # V0 = 20
    X = 35
    # Y0 = 2

    theta *= (math.pi / 180.0);
    return math.tan(theta) * X - (GRAVITY / (2 * (V0 * V0) * (math.cos(theta) * math.cos(theta)))) * (X * X) + Y0;


x = np.linspace(0, 90, 10000)
y = []

for i in range(len(x)):
    y.append(f(x[i], 20, 2))

y2 = []
for i in range(len(x)):
    y2.append(f(x[i], 25, 2))

y3 = []
for i in range(len(x)):
    y3.append(f(x[i], 20, 10))


plt.style.use('Solarize_Light2')

plt.title("Ball Trajectory")
plt.xlabel("Angle (Degrees)")
plt.ylabel("Height (m)")

axes = plt.gca()
axes.set_ylim([-10, 30])

# plt.plot(x, y, '', c='#dc322f')
plt.plot(x, y, label='Base')
plt.plot(x, y2, '', label='V0 = 25')
plt.plot(x, y3, '', label='Y0 = 10')
plt.plot([0, 90], [1, 1], '--', label='Catch')

plt.legend()

plt.savefig('3.png')
plt.show()