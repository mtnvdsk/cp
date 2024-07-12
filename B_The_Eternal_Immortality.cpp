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
    //cin>>t;
    while(t--){
        ll x,y;
        cin>>x>>y;
        if(y-x>=10){
            cout<<0<<endl;
            continue;
        }
        ll ans=1;
        for(ll i=x+1;i<=y;i++) ans=((ans%10)*(i%10))%10;
        cout<<ans<<endl;
    }
    return 0;
}