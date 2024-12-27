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
const int N = 1e5 + 5;  // Updated for larger constraints
const int INF = 1e9 + 7;

int h[N];
int dp[N];

int rec(int i, int k, int n) {
    if (i == n - 1) return 0;  // Base case: reached the last stone
    if (dp[i] != -1) return dp[i];  // Memoization

    int ans = INF;
    rep(j, 1, k + 1) {
        if (i + j < n) {
            ans = min(ans, abs(h[i] - h[i + j]) + rec(i + j, k, n));
        }
    }
    return dp[i] = ans;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        memset(dp, -1, sizeof(dp));
        rep(i, 0, n) cin >> h[i];
        cout << rec(0, k, n) << endl;
    }
    return 0;
}
