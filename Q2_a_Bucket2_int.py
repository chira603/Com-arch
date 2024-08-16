import numpy as np
import time
import resource

def matrix_multiply(matrix_a, matrix_b):
   
    return np.dot(matrix_a, matrix_b)

def create_random_matrix(size):
  
    return np.random.randint(0, 100, (size, size))

def report_times(matrix_sizes):
    
    print("Reporting CPU and System times for integer matrix multiplication:\n")

    for size in matrix_sizes:
        
        matrix_a = create_random_matrix(size)
        matrix_b = create_random_matrix(size)

       
        start_time = time.time()
        start_resources = resource.getrusage(resource.RUSAGE_SELF)

       
        matrix_multiply(matrix_a, matrix_b)

        end_resources = resource.getrusage(resource.RUSAGE_SELF)
        end_time = time.time()

       
        cpu_time = end_time - start_time
        user_time = end_resources.ru_utime - start_resources.ru_utime
        system_time = end_resources.ru_stime - start_resources.ru_stime

       
        print(f"Matrix Size: {size}x{size}")
        print(f"CPU Time: {cpu_time:.6f} seconds")
        print(f"User Time: {user_time:.6f} seconds")
        print(f"System Time: {system_time:.6f} seconds")
        print("-" * 50)


matrix_sizes = [64, 128, 256, 512, 1024]


report_times(matrix_sizes)
