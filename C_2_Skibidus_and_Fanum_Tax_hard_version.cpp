//BY: tardum
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
typedef long long ll;
#define MP make_pair
#define rep(i, a, b) for (ll i = a; i < b; i++)
#define per(i, a, b) for (ll i = a; i > b; i--)
#define all(vec) vec.begin(), vec.end()
#define endl '\n'
const ll N = 1e3+5;
const ll INF = ll(1E18)+16;


signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t=1;
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;
        vector<ll> a(n),b(m);
        rep(i,0,n) cin>>a[i];
        rep(i,0,m) cin>>b[i];
        sort(all(b));
        a.insert(a.begin(),-INF);
        rep(i,1,n+1){
            auto it=lower_bound(b.begin(),b.end(),-10,[&](ll ar,ll _){
                return ar-a[i]<a[i-1];
            });
            if(it==b.end()) continue;
            ll j=*it;
            if(a[i]<a[i-1] && j-a[i]<a[i-1]) continue;
            a[i]=min((a[i]<a[i-1]?INF:a[i]),(j-a[i]<a[i-1]?INF:j-a[i]));
        }
        cout<<(is_sorted(a.begin(),a.end())?"YES":"NO")<<endl;
    }
    return 0;
}