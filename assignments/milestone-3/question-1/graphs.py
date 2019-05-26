import matplotlib.pyplot as plt
import numpy as np
import sys

x = []
theta = []
accel = []
vel = []
dis = []


for line in sys.stdin:
    _x, _theta, _accel, _vel, _dis = line.split()
    x.append(float(_x))
    theta.append(float(_theta))
    accel.append(float(_accel))
    vel.append(float(_vel))
    dis.append(float(_dis))

# z = np.polyfit(x, y, 3)
# z_f = np.poly1d(z)
# z_y = [z_f(x) for x in range(128)]


plt.figure(1)
plt.style.use('Solarize_Light2')

plt.subplot(2, 2, 1)
plt.title("Thruster Angle over Time")
plt.xlabel("Time (s)")
plt.ylabel("Angle (degrees)")
plt.plot(x, theta, '.', label="Angle - without drag")
plt.plot(x, theta, '.', label="Angle - with drag")

plt.subplot(2, 2, 2)
plt.title("Acceleration over Time")
plt.xlabel("Time (s)")
plt.ylabel("Acceleration (m/s^2)")
plt.plot(x, accel, '.', label="Acceleration - without drag")
plt.plot(x, accel, '.', label="Acceleration - with drag")
plt.legend()

plt.subplot(2, 2, 3)
plt.title("Velocity over Time")
plt.xlabel("Time (s)")
plt.ylabel("Acceleration (m/s^2)")
plt.plot(x, vel, '.', label="Velocity - without drag")
plt.plot(x, vel, '.', label="Velocity - with drag")

plt.subplot(2, 2, 4)
plt.title("Displacement over Time")
plt.xlabel("Time (s)")
plt.ylabel("Displacement (m)")
plt.plot(x, dis, '.', label="Displacement - without drag")
plt.plot(x, dis, '.', label="Displacement - with drag")

plt.legend()
plt.show()


