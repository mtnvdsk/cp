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

ll rec(ll i,ll j,ll n,ll m,int p[]){
    if(i==n || m<=0) return 0;
    ll t=0,nt=0;
    if(j==0){
        t=p[i]+rec(i+1,i,n,m-p[i],p);
        nt=
    }
}
signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;
        ll p[n];
        rep(i,0,n) cin>>p[i];

        ll ans=rec(0,0,n,m,p);

    }
    return 0;
}