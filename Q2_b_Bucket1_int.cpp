#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

struct timespec start_time, end_time;

void matrix_multiply_int(int N) {
    vector<vector<int>> A(N, vector<int>(N, 1));
    vector<vector<int>> B(N, vector<int>(N, 2));
    vector<vector<int>> C(N, vector<int>(N, 0));

    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start_time);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end_time);
    double time_taken = (end_time.tv_sec - start_time.tv_sec) + (end_time.tv_nsec - start_time.tv_nsec) / 1e9;
    cout << "Matrix multiplication time for N (meat time)= " << N << " (Integer): " << time_taken << " seconds" << endl;
}

int main() {
    for (int N : {64, 128, 256, 512, 1024}) {
        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start_time);
        matrix_multiply_int(N);
        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end_time);
        double total_time = (end_time.tv_sec - start_time.tv_sec) + (end_time.tv_nsec - start_time.tv_nsec) / 1e9;
        cout << "Overall time taken for N (execution)= " << N << " (Integer): " << total_time << " seconds" << endl;
    }
    return 0;
}
