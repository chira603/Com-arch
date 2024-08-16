import os
import time
import random

def mat_mul(A, B,C, n):
    for i in range(n):
        for j in range(n):
            C[i][j] = sum(A[i][k] * B[k][j] for k in range(n))
    return C

def measure_time(n_values, dtype):
    avg_user_time = [0] * len(n_values)
    avg_sys_time = [0] * len(n_values)

    print(f"Calculating the User time and System time for matrix multiplication ({dtype}):-\n")
    # Measure User and System time
    for i in range(len(n_values)):
        start_times = os.times()
        if dtype == 'int':
            A = [[random.randint(1, 100) for _ in range(n_values[i])] for _ in range(n_values[i])]
            B = [[random.randint(1, 100) for _ in range(n_values[i])] for _ in range(n_values[i])]
        else:
            A = [[random.uniform(1.0, 100.0) for _ in range(n_values[i])] for _ in range(n_values[i])]
            B = [[random.uniform(1.0, 100.0) for _ in range(n_values[i])] for _ in range(n_values[i])]  
        C = [[0] * n_values[i] for _ in range(n_values[i])]
        user_time_accum = 0
        sys_time_accum = 0
        meat_time_start=time.process_time()
        C = mat_mul(A, B,C, n_values[i])
        meat_time_end=time.process_time()
        end_times = os.times()

        user_time_accum += (end_times.user - start_times.user)
        sys_time_accum += (end_times.system - start_times.system)
        
        print(f"User time taken by the program on {dtype} values of size {n_values[i]} is: "
              f"{user_time_accum} seconds")
        print(f"System time taken by the program on {dtype} values of size {n_values[i]} is: "
              f"{sys_time_accum} seconds")
        print("\n")

n_values = [64, 128, 256, 512, 1024]

measure_time(n_values, 'int')
print("Done first.\n")
measure_time(n_values, 'double')