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
#define int long long
const int N = 1e3 + 5;

int rec(const string &s) {
    int n = s.size();
    if (n == 0 || s[0] == '0') return 0;
    
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;

    rep(i, 2, n + 1) {
        int oneDigit = s[i - 1] - '0';
        int twoDigit = (s[i - 2] - '0') * 10 + oneDigit;
        
        if (oneDigit >= 1) dp[i] += dp[i - 1];
        if (twoDigit >= 10 && twoDigit <= 26) {
            dp[i] += dp[i - 2];
        }
    }
    
    return dp[n];
}

signed main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);
    
    while (true) {
        string x;
        cin >> x;
        if (x == "0") break;
        
        cout << rec(x) << endl;
    }
    
    return 0;
}
