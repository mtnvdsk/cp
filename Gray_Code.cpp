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

vector<string> rec(int n){
    if(n==1){
        return {"0","1"};
    }

    vector<string> a;
    vector<string> b=rec(n-1);
    for(int i=0;i<b.size();i++){
        a.push_back("0"+b[i]);
    }
    for(int i=b.size()-1;i>=0;i--){
        a.push_back("1"+b[i]);
    }
    return a;
}


signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        ll n;
        cin>>n;

        vector<string> ans=rec(n);
        for(int i=0;i<ans.size();i++) cout<<ans[i]<<endl;
    }
    return 0;
}