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
// #define int long long
const int N = 1e3+5;

int rec(int a,int b,int n){
    a%=n;
    int res=1;
    while(b>0){
        if(b%2){
            res=(res*a)%n;
        }
        a=(a*a)%n;
        b=b/2;
    }
    return res;
}
signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // int t=1;
    // cin>>t;
    
    int x,y,n;
    while(cin>>x>>y>>n){
        int temp=rec(x,y,n);
        cout<<temp<<endl;
    }
    return 0;
}