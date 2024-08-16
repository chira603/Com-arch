#include <iostream>
#include <vector>
#include <sys/times.h>
#include <unistd.h>
#include <cstdlib>
#include <ctime>

// Function to perform matrix multiplication
void matrixMultiply(int** matrixA, int** matrixB, int** resultMatrix, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            resultMatrix[i][j] = 0;
            for (int k = 0; k < size; ++k) {
                resultMatrix[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}

// Function to create a matrix with random integers
int** createRandomMatrix(int size, bool isInt) {
    int** matrix = new int*[size];
    for (int i = 0; i < size; ++i) {
        matrix[i] = new int[size];
        for (int j = 0; j < size; ++j) {
            matrix[i][j] = rand() % 100 + 1; // Random integers between 1 and 100
        }
    }
    return matrix;
}

// Function to delete a matrix
void deleteMatrix(int** matrix, int size) {
    for (int i = 0; i < size; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int main() {
    const int sizes[] = {64, 128, 256, 512, 1024};
    const int numSizes = sizeof(sizes) / sizeof(sizes[0]);
    const int clkTick = sysconf(_SC_CLK_TCK);

    std::cout << "Reporting CPU and System times for matrix multiplication:\n";

    for (int index = 0; index < numSizes; ++index) {
        int size = sizes[index];

        // Allocate matrices
        int** matrixA = createRandomMatrix(size, true);
        int** matrixB = createRandomMatrix(size, true);
        int** resultMatrix = new int*[size];
        for (int i = 0; i < size; ++i) {
            resultMatrix[i] = new int[size];
        }

        // Measure time
        struct tms startTimes, endTimes;
        clock_t startClock, endClock;
        
        startClock = clock();
        times(&startTimes);

        matrixMultiply(matrixA, matrixB, resultMatrix, size);

        endClock = clock();
        times(&endTimes);

        double cpuTime = (double)(endClock - startClock) / CLOCKS_PER_SEC;
        double userTime = (double)(endTimes.tms_utime) / clkTick;
        double systemTime = (double)(endTimes.tms_stime) / clkTick;

        // Report times
        std::cout << "Matrix Size: " << size << "x" << size << "\n";
        std::cout << "CPU Time: " << cpuTime << " seconds\n";
        std::cout << "User Time: " << userTime << " seconds\n";
        std::cout << "System Time: " << systemTime << " seconds\n";
        std::cout << "--------------------------------------\n";

        // Clean up
        deleteMatrix(matrixA, size);
        deleteMatrix(matrixB, size);
        deleteMatrix(resultMatrix, size);
    }

    return 0;
}
