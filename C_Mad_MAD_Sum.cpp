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
const int N = 2e5+20;
ll ans;
ll a[N],c[N];
ll n;


void operate(){
    rep(i,1,n+1) c[i]=0;
    ll mx=0;
    rep(i,0,n){
        ll temp=a[i];
        ans+=temp;
        c[temp]++;
        if(c[temp]>=2) mx=max(mx,temp);
        a[i]=mx;
    }
}
signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        cin>>n;
        ans=0;
        rep(i,0,n) cin>>a[i];

        operate();
        operate();
        per(i,n-1,-1){
            ans+=(1LL)*(n-i)*a[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}