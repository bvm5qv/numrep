import numpy as np

def intUnderOverFlow(x):
    under = 0
    over = 0
    for i in range(x):
        print("loop number: " + str(i) + ", under: " + str(under) + ", over: " + str(over))
        under -= 1
        over += 1

intUnderOverFlow(2**32)
