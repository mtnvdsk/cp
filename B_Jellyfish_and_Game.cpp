//BY: mtnvdsk
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
const int N = 1e3+5;


signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> a(n), b(m);
        int sum = 0;
        rep(i, 0, n) {
            cin >> a[i];
            sum += a[i];
        }
        rep(i, 0, m) cin >> b[i];

        if (k % 2 == 0) {
            cout << sum << endl;
        } else {
            int min_a = *min_element(a.begin(), a.end());
            int max_b = *max_element(b.begin(), b.end());
            if(min_a>max_b) cout<<sum<<endl;
            else cout << (sum - min_a + max_b) << endl;
        }
    }
    return 0;
}