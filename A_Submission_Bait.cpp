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

void solve(){
    ll n;
    cin>>n;
    vector<ll> a(55);
    rep(i,1,n+1){
        int x;
        cin>>x;
        a[x]++;
    }
    int ans=0;
    rep(i,1,n+1){
        if(a[i]%2==1){
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
}
signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}