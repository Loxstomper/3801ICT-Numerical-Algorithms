import matplotlib.pyplot as plt
from math import sin, cos

# positions

data = [0.75, 5120,
0.72, 5370,
0.70, 5560,
0.68, 5800,
0.67, 6030,
0.66, 6240]

x = [data[i] for i in range(len(data)) if i % 2 == 0]
y = [data[i] for i in range(len(data)) if i % 2 == 1]

print(x)
print(y)

plt.style.use('Solarize_Light2')

fig = plt.figure(1)

ax = fig.add_subplot(111, projection='polar')
plt.plot(x, y, 'o-', c="#dc322f", s=[5 for _ in range(len(x))])

ax.set_title("Airplane Position (Polar Coordinates)")
ax.set_rmin(4500)
ax.set_rmax(6500)
ax.set_thetamin(0)
ax.set_thetamax(180)
ax.set_yticklabels([])



# cart = fig.add_subplot(333)

# cart_x = [y[i] * cos(x[i]) for i in range(len(x))]
# cart_y = [y[i] * sin(x[i]) for i in range(len(x))]


# cart_c = cart.scatter(cart_x, cart_y, c='red')

plt.tight_layout()
fig.savefig('test.png')
plt.show()



# 200, 0.75, 5120
# 202, 0.72, 5370
# 204, 0.70, 5560
# 206, 0.68, 5800
# 208, 0.67, 6030
# 210, 0.66, 6240