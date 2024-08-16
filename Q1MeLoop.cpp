#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

void print_fibonacci_loop_memoization(int count) {
    vector< long long> fib(count);
    fib[0] = 0;
    if (count > 1) fib[1] = 1;

    for (int i = 2; i < count; ++i) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    for (const auto& num : fib) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    struct timespec start, end;
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);

    print_fibonacci_loop_memoization(50);

    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);
    double time_taken = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    cout << "Time taken for loop with memoization: " << time_taken << " seconds" << endl;
    return 0;
}
