#include <iostream>
#include <vector>
using namespace std;
#define int long long

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n+1);
        int sum1 = 0, sum2 = 0, sum = 0;
        for (int i = 1; i <=n; i++) {
            cin >> a[i];
            if (i % 2 == 0) {
                sum2 += a[i]; 
            } else {
                sum1 += a[i];
            }
            sum += a[i]; 
        }

        if (sum % n == 0) {
            int average = sum / n;
            int o = (n + 1) / 2;
            int e = n-o;
            
            if ((sum1 == o * average) && (sum2 == e * average)) {
                cout << "YES" << endl;
                continue;
            }
        }
        cout << "NO" << endl;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
