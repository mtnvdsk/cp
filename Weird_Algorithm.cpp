//BY: tardum
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

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        ll n;
        cin>>n;
        cout<<n<<" ";
        while(n!=1){
            if(n%2==0){
                n=n/2;
                cout<<n<<" ";
            }
            else{
                n=(n*3+1);
                cout<<n<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}