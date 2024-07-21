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
// typedef long long ll;
#define int long long 
const int N = 1e3+5;

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        int n;
		cin >> n;
		if (__builtin_popcountll(n) == 1) {
			cout << "1\n" << n << '\n';
			continue;
		}
		int res = __builtin_popcountll(n) + 1;
		cout << res << '\n';
		for (int i = 0; i < res; i++) {
			int cnt = 0, cur = 0;
			int val = 0;
			for (int l = 62; l >= 0; l--) {
				if (n & (1ll << l)) {
					cnt++;
					if (cnt <= i) val += (1ll << l);
					else {
						if (cur) val += (1ll << l);
						cur = 1 - cur;
					}
				}
			}
			cout << val << ' ';
		}
		cout << '\n';

    }
    return 0;
}
