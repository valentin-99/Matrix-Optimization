import matplotlib.pyplot as plt
  
x = [200, 400, 600, 800, 1000, 1200, 1400, 1600]

y1 = [0.006912, 0.031861, 0.103003, 0.246950, 0.458059, 0.738004, 1.188714, 1.753768]
plt.plot(x, y1, label = "blas")

y2 = [00.099184, 0.666191, 2.243553, 5.723393, 12.010465, 21.113308, 37.291985, 60.910107]
plt.plot(x, y2, label = "neopt")

y3 = [0.066071, 0.518323, 1.501461, 3.502551, 6.898539, 11.827102, 20.103453, 33.874283]
plt.plot(x, y3, label = "opt_m")

plt.xlabel('N = size of matrix')
plt.ylabel('Time (seconds)')
plt.title('Comparative analysis of performance')

plt.legend()

plt.show()

