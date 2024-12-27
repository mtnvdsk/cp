#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int l, r, k;
        cin >> l >> r >> k;

        // Special case when k = 1
        if (k == 1) {
            cout << (r - l + 1) << '\n';
            continue;
        }

        int max_operations = 0;

        // Check for multiples of numbers up to sqrt(r)
        for (int m = 1; m * m <= r; ++m) {
            // Count multiples of m in range [l, r]
            if (m >= l) {
                int count_multiples = (r / m) - ((l - 1) / m);
                if (count_multiples >= k) {
                    max_operations++;
                }
            }

            // Check for the paired divisor if it's different
            if (m != 0 && r / m != m) {
                int d = r / m; // This is the paired divisor
                if (d >= l) {
                    int count_multiples = (r / d) - ((l - 1) / d);
                    if (count_multiples >= k) {
                        max_operations++;
                    }
                }
            }
        }

        cout << max_operations << '\n';
    }

    return 0;
}