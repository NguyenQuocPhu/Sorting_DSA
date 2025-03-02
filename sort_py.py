import numpy as np
import time 

for i in range(1,10):
    filename = "test_" + str(i) + ".inp"
    with open(filename, "r", encoding = "utf-8") as file:
        arr = file.read()
    a = np.fromstring(arr, dtype = int, sep = " ")
    st = time.time()
    sorted_arr = np.sort(a)
    en = time.time()
    runningtime = (en - st) * 1000
    print(f"Runtime: {runningtime:.3f} ms")
