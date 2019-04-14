import matplotlib.pyplot as plt
from math import sin, cos

velocityTimes = [202, 204, 206, 208]
velocityX = [126.569, 118.181, 118.481, 104.907]
velocityY = [22.965, 26.526, 40.6738, 44.7124]

# accelerationTimes = [204, 206]
# accelerationX = [-2.02209, -3.31845]
# accelerationY = [4.4272, 4.54661]

accelerationTimes = [202, 204, 206, 208]
accelerationX = [-18.906, 10.5184, -10.2191, -3.354]
accelerationY = [-2.48765, 6.04864, 8.09919, -4.06058]



plt.style.use('Solarize_Light2')

fig = plt.figure()
ax = plt.subplot(111)

# velocity
# ax.plot(velocityTimes, velocityX, 'blue', label="X")
# ax.plot(velocityTimes, velocityY, 'red', label="Y")
# plt.title("Velocity over time")
# plt.xlabel("Time (s)")
# plt.ylabel("Velocity (m/s)")
# # ax.legend()

# acceleration
ax.plot(accelerationTimes, accelerationX, 'blue', label="X")
ax.plot(accelerationTimes, accelerationY, 'red', label="Y")
plt.title("Acceleration over time")
plt.xlabel("Time (s)")
plt.ylabel("Acceleration (m/s^2)")
ax.legend()

plt.show()

