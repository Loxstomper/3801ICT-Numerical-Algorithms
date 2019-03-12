#!/bin/python3

import matplotlib.pyplot as plt

x = [0, 2, 4, 6, 8, 10, 12, 14, 16]
y = [0, 1.9, 2, 2, 2.4, 2.6, 2.25, 1.12, 0]

plt.style.use('Solarize_Light2')

plt.title("River Depths")
plt.xlabel("Width (m)")
plt.ylabel("Height (m)")

plt.plot(x, y, 'o--', c='#dc322f')
plt.fill(x, y, alpha=0.01, hatch='/')

# regression R^2 = 1, 8th order
# 5.07657E-07 x⁸ − 3.26606E-05 x⁷ + 0.000858724 x⁶ − 0.0117101 x⁵ + 0.0854414 x⁴ - 0.295554 x³ + 0.196962 x² + 1.21667 x − 1.86636E-12

# \int _0^{16}\:5.07657\cdot 10^{-7}\:x^8\:−\:3.26606\cdot 10^{-5}\:x^7\:+\:0.000858724\:x^6\:−\:0.0117101\:x^5\:+\:0.0854414\:x^4-\:0.295554\:x^3\:+\:0.196962\:x^2\:+\:1.21667\:x\:−\:1.86636\cdot 10^{-12}\:dx

plt.show()