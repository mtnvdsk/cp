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
typedef long long ll;
const int N = 1e3+5;

vector<int> dp;
int rec(int n){
    if(n == 0) return 0;
    if(dp[n]!=-1) return dp[n];
    string temp=to_string(n);
    int ans=INT_MAX;
    for(char c:temp){
        int digit=c-'0';
        if(digit>0){
            ans=min(ans,rec(n-digit)+1);
        }
    }
    return dp[n]=ans;
}

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        int n;
        cin>>n;
        dp.assign(n+1,-1);
        cout<<rec(n)<<endl;
    }
    return 0;
}