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
        ll n, m, k;
        cin >> n >> m >> k;
        k--;
        vector<int> a(n), b(m);
        int sum = 0;
        rep(i, 0, n) cin >> a[i];
        rep(i, 0, m) cin >> b[i];

        int x=0,y=0;
        rep(i,1,n) if(a[i]<a[x]) x=i;
        rep(i,1,m) if(b[i]>b[y]) y=i;
        if(a[x]<b[y]) swap(a[x],b[y]);
        if(k&1){
            x=0,y=0;
            rep(i,1,n) if(a[i]>a[x]) x=i;
            rep(i,1,m) if(b[i]<b[y]) y=i;
            swap(a[x],b[y]);
        }
        ll ans=0;
        rep(i,0,n) ans+=a[i];
        cout<<ans<<endl;
    }
    return 0;
}