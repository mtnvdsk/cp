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
        int n,m;
        cin>>n>>m;
        vector<int> a[m];
        rep(i,0,n){
            rep(j,0,m){
                int x;
                cin>>x;
                a[j].PB(x);
            }
        }

        int ans=0;
        rep(i,0,m){
            sort(a[i].begin(),a[i].end());
        }

        rep(i,0,m){
            vector<int> res(n,0);
            res[n-1]=a[i][n-1];
            for(int j=n-2;j>=0;j--){
                res[j]=res[j+1]+a[i][j];
            }

            rep(j,0,n-1){
                int c=res[j+1]-(n-1-j)*a[i][j];
                ans+=c;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}