#!/bin/python3

import matplotlib.pyplot as plt
import sys

x = []
y = []

truncX = []
truncY = []


lineNumber = 0
for line in sys.stdin:
    # h and error
    if lineNumber % 2 == 0:
        x.append(float(line.split()[0]))
        y.append(float(line.split()[1]))

    # h and truncation error
    if lineNumber % 2 == 1:
        truncX.append(float(line.split()[0]))
        truncY.append(float(line.split()[1]))

    lineNumber += 1


# find min error and corresponding h


# plt.yscale('log')
# plt.xscale('log')
# plt.plot(x, y, 'o-', c='r')
# plt.plot(truncX, truncY, 'o-', c='b')
plt.plot(x, y, 'o--', c='r')
# plt.plot(truncX, truncY, 'o', c='b')
plt.xlabel("H - Step Size")
plt.ylabel("True Error")

plt.show()
