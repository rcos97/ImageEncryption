import matplotlib.pyplot as plt
import numpy as np
def test(x):
    x = np.array(x);
    print(x)
    y = np.arange(1,len(x)+1)
    print(y)
    plt.scatter(y,x)
    plt.show()