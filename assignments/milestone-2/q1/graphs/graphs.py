import math
import matplotlib.pyplot as plt
import numpy as np
from sys import stdin

x = [0]
yE = [0]
yM = [0]
yH = [0]
yR = [0]
yA = [0]
xA = [0]

for line in stdin:
    z = line.split()

    # if len(z) == 2:
    #     xA.append(float(z[0]))
    #     yA.append(float(z[1]))

    #     continue

    for i in range(len(z)):
        z[i] = float(z[i])

    x.append(z[0])
    yE.append(z[1])
    yM.append(z[2])
    yH.append(z[3])
    yR.append(z[4])
    yA.append(z[5])


plt.style.use('Solarize_Light2')

plt.title("Mast deflection - h = 0.125")
plt.xlabel("x (m)")
plt.ylabel("Deflection (m)")

axes = plt.gca()
# axes.set_ylim([-10, 30])
# axes.set_xlim([0, 1])

# plt.plot(x, y, '', c='#dc322f')

plt.plot(x, yE, label='Euler')
plt.plot(x, yM, label='Midpoint')
plt.plot(x, yH, label='Huen')
plt.plot(x, yR, label='RK4')
plt.plot(x, yA, label='Analytical')

# plt.plot(x, y2, '', label='V0 = 25')
# plt.plot(x, y3, '', label='Y0 = 10')
# plt.plot([0, 90], [1, 1], '--', label='Catch')

# plt.plot(x, yE, label='0.05')
# plt.plot(x, yM, label='0.10')
# plt.plot(x, yH, label='0.15')
# plt.plot(x, yR, label='0.20')

plt.legend()

# plt.savefig('3.png')
plt.show()