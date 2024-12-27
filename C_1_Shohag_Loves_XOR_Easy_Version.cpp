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
        ll x,m;
        cin>>x>>m;
        int ans=0;
        rep(y,1,min(2*x, m+1)){
            if(x==y) continue;
            else{
                int temp=x^y;
                if(x%temp==0 || y%temp==0) ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}