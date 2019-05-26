from numpy.polynomial.polynomial import Polynomial
from scipy.interpolate import lagrange

x = [0, 63, 127]
y = [8.89142, 5.66585, 2.29296]

poly = lagrange(x, y)
print(Polynomial(poly).coef)

# y = 63 
# z = y * float(-1.18258460e-05) + y * float(-5.04544955e-02) + y * float(8.89142000e+00)
# print(z)
y = 64
z = y * float(-1.18258460e-05) + y * float(-5.04544955e-02) + float(8.89142000e+00)
print(z)

