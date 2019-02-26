#!/bin/python3

import matplotlib.pyplot as plt
import sys

raw = [x.strip() for x in sys.stdin]

labels = ['V', 'A']
v = []
a = []

raw.pop(0)

for data in raw:
    if data == 'A':
        break
    
    v.append(float(raw.pop(0)))

raw.pop(0)

for data in raw:
    a.append(float(data))

plt.scatter([1, 2, 3, 4, 5], v)
plt.scatter([1, 2, 3, 4], a)
plt.show()
