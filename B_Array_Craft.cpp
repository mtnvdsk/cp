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
    ll t=1;
    cin>>t;
    while(t--){
        int n,x,y;
        cin>>n>>x>>y;
        x--;y--;
        vector<ll> a(n,1);
        int d=-1;
        per(i,y-1,-1){
            a[i]=d;
            d=-d;
        }
        d=-1;
        rep(i,x+1,n){
            a[i]=d;
            d=-d;
        }
        rep(i,0,n) cout<<a[i]<<" ";
        cout<<endl;
    }
    return 0;
}