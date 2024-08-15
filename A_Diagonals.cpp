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
        ll n, k;
        cin>>n>>k;
        if(k==0){
            cout<<0<<endl;
            continue;
        }

        ll ans = 0;
        if(k <= n){
            cout<<1<<endl;
            continue;
        }

        k -= n;
        ans++;
        n--;

        while(n >= 0 && k > 0){
            if(k <= n){
                ans++;
                k = 0;
                break;
            } else if(k <= 2 * n){
                ans += 2; 
                k = 0;
                break;
            } else {
                k -= 2 * n;
                ans += 2;
                n--;
            }
        }

        cout<<ans<<endl;
    }
    return 0;
}
