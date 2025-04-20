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

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        map<int,int> mp;
        int c=0,t=0;
        for(int i=0;i<n-1;i++){
            if(s[i]=='<') c++;
            if(s[i]=='>') t++;
        }
        vector<int> ans(n);
        for(int i=0;i<n-1;i++){
            if(s[i]=='<') ans[i+1]=c--;
            else ans[i+1]=n-t+1,t--;
        }
        int tt=0;
        int sum=(n*(n+1))/2;
        for(int i=0;i<n;i++){
            tt+=ans[i];
        }
        ans[0]=sum-tt;
        for(auto i:ans) cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}