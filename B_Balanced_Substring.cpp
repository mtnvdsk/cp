// BY: mtnvdsk
#include <bits/stdc++.h>
using namespace std;

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
const int INF = 0x3f3f3f3f;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        string s;
        cin >> s;

        ll sum = n;
        ll ans = 0;
        vector<ll> m(2 * n + 1, INF);
        m[sum] = 0;
        for (ll i = 1; i <= n; i++) {
            if (s[i - 1] == '0') 
                sum--;
            else 
                sum++;
            m[sum] = min(m[sum], i);
            ans = max(ans, i - m[sum]);
        }
        cout << ans << endl;
    }
    return 0;
}
