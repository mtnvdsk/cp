#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        long long x, y;
        cin >> n >> x >> y;

        vector<long long> a(n);
        long long totalSum = 0;

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            totalSum += a[i];
        }
        long long L = totalSum - y;
        long long R = totalSum - x;
        sort(a.begin(), a.end());

        long long count = 0;
        for (int i = 0; i < n; ++i) {
            long long targetLow = L - a[i];
            long long targetHigh = R - a[i];
            auto lower = lower_bound(a.begin() + i + 1, a.end(), targetLow);
            auto upper = upper_bound(a.begin() + i + 1, a.end(), targetHigh);

            count += (upper - lower);
        }

        cout << count << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
