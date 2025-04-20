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
const int N = 1e3+5;

const int MOD = 998244353;

int modExp(int base, int exp) {
    int result = 1;
    while (exp) {
        if (exp & 1) result = (1LL * result * base) % MOD;
        base = (1LL * base * base) % MOD;
        exp >>= 1;
    }
    return result;
}
void fwht(vector<int>& a, bool invert) {
    int n = a.size();
    for (int len = 1; 2 * len <= n; len <<= 1) {
        for (int i = 0; i < n; i += 2 * len) {
            for (int j = 0; j < len; ++j) {
                int u = a[i + j];
                int v = a[i + j + len];
                a[i + j] = (u + v) % MOD;
                a[i + j + len] = (u - v + MOD) % MOD;
            }
        }
    }
    if (invert) {
        int inv_n = modExp(n, MOD - 2);
        for (int &x : a)
            x = 1LL * x * inv_n % MOD;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        int sz = 1 << m;
    
        vector<pair<int, int>> intervals(n);
        for (auto& [l, r] : intervals)
            cin >> l >> r;
    
        vector<int> dp(sz, 0);
        dp[0] = 1;
    
        for (auto& [l, r] : intervals) {
            vector<int> f(sz, 0);
            for (int i = l; i <= r; ++i) {
                if (i < sz) f[i] = 1;
            }
    
            fwht(dp, false);
            fwht(f, false);
    
            for (int i = 0; i < sz; ++i)
                dp[i] = 1LL * dp[i] * f[i] % MOD;
    
            fwht(dp, true);
        }
    
        int result = 0;
        for (int x = 0; x < sz; ++x) {
            int fx = dp[x];
            int gx = 1LL * fx * modExp(2, x) % MOD;
            result ^= gx;
        }
    
        cout << result << "\n";
    }
    

    return 0;
}
