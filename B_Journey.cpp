#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
    int t;
    cin >> t;

    while (t--) {
        long long n, a, b, c;
        cin >> n >> a >> b >> c;

        long long cycle_sum = a + b + c;
        long long full_cycles = n / cycle_sum;
        long long total_distance = full_cycles * cycle_sum;
        long long days = full_cycles * 3;

        if (total_distance >= n) {
            cout << days << endl;
            continue;
        }

        if (total_distance + a >= n) {
            cout << days + 1 << endl;
        } else if (total_distance + a + b >= n) {
            cout << days + 2 << endl;
        } else {
            cout << days + 3 << endl;
        }
    }
}

int main() {
    solve();
    return 0;
}
