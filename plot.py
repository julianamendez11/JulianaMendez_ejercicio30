import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation

dat=np.loadtxt("onda.dat")
x=dat.shape[1]
t=dat.shape[0]
print((x), (t))

xdata, ydata = np.linspace(0,1,x), []

fig, ax = plt.subplots(figsize=(6,5))

ax.grid()
ju, = plt.plot(xdata, dat[0])
def init():  
    ax.set_xlim(0, 1)
    ax.set_ylim(-0.05, 0.05)
    ax.set_xlabel("Posicion en metros")
    ax.set_ylabel("U")
    return ju,


def animate(i):
    ju.set_ydata(dat[i])
    ax.set_title("Tiempo: "+ str("{0:.2f}".format(2*i/(t-1)))+ " segundos")
    return ju,


ani = animation.FuncAnimation(
    fig, animate, init_func=init, interval=100,frames=range(t), blit=True,repeat=True)

ani.save("onda.gif",fps=10)
