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
        int x,y,a;
        cin>>x>>y>>a;
        int t=0;
        int s=0;
        while(t<=a){
            if(s==0){
                t+=x;
                s=1;
            }
            else{
                t+=y;
                s=0;
            }
        }
        if(s==0) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}