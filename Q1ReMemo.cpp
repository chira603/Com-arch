#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

vector< long long> memo(50, -1);

 long long fibonacci_memoization(int n) {
    if (memo[n] != -1) return memo[n];
    if (n <= 1) return n;
    memo[n] = fibonacci_memoization(n - 1) + fibonacci_memoization(n - 2);
    return memo[n];
}

void print_fibonacci_memoization(int count) {
    for (int i = 0; i < count; ++i) {
        cout << fibonacci_memoization(i) << " ";
    }
    cout << endl;
}

int main() {
    struct timespec start, end;
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);

    print_fibonacci_memoization(50);

    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);
    double time_taken = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    cout << "Time taken for recursion with memoization: " << time_taken << " seconds" << endl;
    return 0;
}
