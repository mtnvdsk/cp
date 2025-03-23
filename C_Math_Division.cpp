#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;

long long inv(long long a, long long mod) {
    long long m0 = mod, t, q;
    long long x0 = 0, x1 = 1;
    if (mod == 1)
        return 0;
    while (a > 1) {
        q = a / mod;
        t = mod;
        mod = a % mod, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    if (x1 < 0)
        x1 += m0;
    return x1;
}

long long expectedOperations(const string& s) {
    int n = s.length();
    long long expected = 0;
    long long power = 1;
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == '1') {
            expected = (expected + power) % MOD;
        }
        power = (power * 2) % MOD;
    }
    // Subtract 1 because E[1] = 0
    expected = (expected - 1 + MOD) % MOD;
    return expected;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        cout << expectedOperations(s) << '\n';
    }

    return 0;
}