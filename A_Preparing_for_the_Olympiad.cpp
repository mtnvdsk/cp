#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> b[i];

        int max_difference = 0;

        for (int i = 0; i < n; ++i) {
            int gain = a[i];
            if (i + 1 < n) gain -= b[i + 1];
            if (gain > 0) max_difference += gain;
        }

        cout << max_difference << endl;
    }
}

int main() {
    solve();
    return 0;
}
