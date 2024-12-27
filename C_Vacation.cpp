//BY: tardum
#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = a; i > b; i--)
#define all(vec) vec.begin(), vec.end()
#define endl '\n'
#define int long long
const int N = 1e3+5;

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n],b[n],c[n];
        rep(i,0,n){
            cin>>a[i]>>b[i]>>c[i];
        }
        vector<vector<int>> dp;
        dp.assign(n,vector<int>(3,0));
        dp[0][0]=a[0];
        dp[0][1]=b[0];
        dp[0][2]=c[0];
        rep(i,1,n){
            dp[i][0]=a[i]+max(dp[i-1][1],dp[i-1][2]);
            dp[i][1]=b[i]+max(dp[i-1][0],dp[i-1][2]);
            dp[i][2]=c[i]+max(dp[i-1][0],dp[i-1][1]);
        }
        cout<<max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2]));
    }
    return 0;
}