import numpy as np
import time

def matrix_multiply_int(N):
    A = np.ones((N, N), dtype=int)
    B = np.full((N, N), 2, dtype=int)
    
    start_meat = time.process_time()
    C = np.dot(A, B)
    end_meat = time.process_time()

    meat_time = end_meat - start_meat
    return meat_time

for N in [64, 128, 256, 512, 1024]:
    total_start_time = time.process_time()
    print(f"Running for N = {N} (Int)")
    
    # Measure meat portion time
    meat_time = matrix_multiply_int(N)
    
    total_end_time = time.process_time()
    total_execution_time = total_end_time - total_start_time

    print(f"Meat portion time: {meat_time:.6f} seconds")
    print(f"Total program execution time: {total_execution_time:.6f} seconds")

    # Check to avoid division by zero
    if total_execution_time > 0:
        proportion = meat_time / total_execution_time
        print(f"Meat portion time proportion: {proportion:.2%}")
    else:
        print("Total execution time is too small to measure accurately.")

    print("-" * 50)
