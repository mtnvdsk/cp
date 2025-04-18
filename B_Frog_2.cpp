//BY: tardum
#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = a; i > b; i--)
#define all(vec) vec.begin(), vec.end()
#define endl '\n'
typedef long long ll;
const int N = 1e3 + 5;

vector<int> h;
vector<int> dp;
int n;

int rec(int l, int k) {
    // Pruning
    if (l >= n - 1) return 0;
    // Cache check
    if (dp[l] != -1) return dp[l];

    // Compute
    int ans = INT_MAX;
    rep(i, 1, k + 1) {
        if (l + i < n) {  // Ensure we don't exceed bounds
            ans = min(ans, abs(h[l] - h[l + i]) + rec(l + i, k));
        }
    }
    // Save and return
    return dp[l] = ans;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t = 1;
    // cin >> t;
    while (t--) {
        int k;
        cin >> n >> k;
        h.assign(n, 0);
        rep(i, 0, n) {
            cin >> h[i];
        }
        dp.assign(n, -1);
        cout << rec(0, k) << endl;
    }
    return 0;
}
