import matplotlib.pyplot as plt
import numpy as np
import sys

x = []
y = []

for line in sys.stdin:
    a, b = line.split()
    x.append(float(a))
    y.append(float(b))

z = np.polyfit(x, y, 3)
z_f = np.poly1d(z)
z_y = [z_f(x) for x in range(128)]


plt.style.use('Solarize_Light2')
plt.title("Thruster Angle over Time")
plt.xlabel("Time (s)")
plt.ylabel("Angle (degrees)")
plt.plot(x, y, 'o', label="Data")
plt.plot(x, z_y, '-', c='red', linewidth='2', label="Regression: " + str(z))
plt.legend()
plt.show()


