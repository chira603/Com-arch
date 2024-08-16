#include <iostream>
#include <ctime>

#include <iomanip>

using namespace std;
void print_fibonacci_loop(int count) {
     long long a = 0, b = 1;
    for (int i = 0; i < count; ++i) {
        cout << a << " ";
         long long next = a + b;
        a = b;
        b = next;
    }
    cout << endl;
}

int main() {
    struct timespec start, end;
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);

    print_fibonacci_loop(50);

    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);
    double time_taken = double(end.tv_sec - start.tv_sec) + double(end.tv_nsec - start.tv_nsec) / double(1e9);
    cout << "Time taken for loop: " << time_taken << setprecision(9) <<" seconds" << endl;
    return 0;
}
