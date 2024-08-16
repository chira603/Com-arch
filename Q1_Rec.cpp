#include <iostream>
#include <ctime>
using namespace std;

long long fibonacci_recursive(int n) {
    if (n <= 1) return n;
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

void print_fibonacci_recursive(int count) {
    for (int i = 0; i < count; ++i) {
        cout << fibonacci_recursive(i) << " ";
    }
    cout << endl;
}

int main() {
    struct timespec start, end;
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);

    print_fibonacci_recursive(50);

    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);
    double time_taken = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    cout << "Time taken for recursion: " << time_taken << " seconds" << endl;
    return 0;
}
