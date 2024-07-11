#include <bits/stdc++.h>
using namespace std;

#define int long long
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define rep(i, a, b) for (int i = a; i < b; i++)
#define all(vec) vec.begin(), vec.end()
#define endl '\n'


signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> a[n];
        rep(i,0,n){
            rep(j,0,n){
                int x;
                cin>>x;
                a[i].PB(x);
            }
        }

        int ans=0;
        rep(i,0,n){
            rep(j,0,n){
                if(a[i][j]!=a[n-i-1][n-j-1]) ans++;
            }
        }
        ans/=2;
        if(ans>k) cout<<"NO"<<endl;
        else{
            k-=ans;
            if(n&1) cout<<"YES"<<endl;
            else if(k&1) cout<<"NO"<<endl;
            else cout<<"YES"<<endl;
        }
    }
    return 0;
}