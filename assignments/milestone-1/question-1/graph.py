#!/bin/python3

import matplotlib.pyplot as plt
import sys

x = []
y = []


for line in sys.stdin:
    x.append(float(line.split()[0]))
    y.append(float(line.split()[1]))

print(x[500:510])
print(y[500:510])

# plt.yscale("log")
plt.plot(x, y, 'o-')
plt.show()
