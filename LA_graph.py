import numpy as np
import matplotlib as plt


data=np.loadtxt("tray.txt")
t=data[:, 0]
x=data[:, 1]
v=data[:, 2]



plt.figure()
plt.plot(t, x)
plt.savefig("pos.png")

plt.figure()
plt.plot(t,v)
plt.savefig("vel.png")

plt.figure()
plt.plot(x,v)
plt.savefig("phase.png")


