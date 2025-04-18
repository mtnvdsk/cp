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

int dx[4] = {-1, 1, -1, 1}, dy[4] = {-1, -1, 1, 1};
signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        int a,b,x1,x2,y1,y2;
        cin>>a>>b>>x1>>y1>>x2>>y2;
        set<pair<int,int>> s1,s2;
        rep(i,0,4){
            s1.insert({x1+dx[i]*a,y1+dy[i]*b});
            s1.insert({x1+dx[i]*b,y1+dy[i]*a});
            s2.insert({x2+dx[i]*a,y2+dy[i]*b});
            s2.insert({x2+dx[i]*b,y2+dy[i]*a});
        }
        int ans=0;
        for(auto i:s1){
            if(s2.find(i)!=s2.end()) ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}