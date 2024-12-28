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
        int a,b,c,m;
        cin>>m>>a>>b>>c;
        int ans=0;
        int x=m,y=m;
        int take=min(x,a);
        ans+=take;
        x-=take;
        take=min(y,b);
        ans+=take;
        y-=take;
        take=min(x+y,c);
        ans+=take;
        cout<<ans<<endl;
    }
    return 0;
}