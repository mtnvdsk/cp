#include <iostream>
#include <cmath>
using namespace std;

long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int main() {
    int T;
    cin >> T;

    for (int t = 1; t <= T; ++t) {
        long long A, B, C, P;
        cin >> A >> B >> C >> P;
        int count = 0;
        for (long long x = 0; x * A <= P; ++x) {
            for (long long y = 0; y * B <= P - x * A; ++y) {
                long long remaining = P - x * A - y * B;
                if (remaining % C == 0) {
                    ++count;
                }
            }
        }
        cout << "Case " << t << ": " << count << endl;
    }

    return 0;
}
