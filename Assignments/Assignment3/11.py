import matplotlib as plt
import matplotlib.pyplot as plt
import numpy as np


f = open('Plot.txt', 'r')

x = []
y = []
for line in f:
    x.append(float(line.split(',')[0]))
    y.append(float(line.split(',')[1]))
plt.plot(x, y)
plt.xlabel('Number of points')
plt.ylabel('Time in seconds')
plt.title('Plot of time vs number of points')
# fit a square line to the data
z = np.polyfit(x, y, 2)
p = np.poly1d(z)
plt.plot(x, p(x), 'r--')
plt.show()
