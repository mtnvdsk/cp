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
        if(n<=4){
            cout<<"-1"<<endl;
            continue;
        }
        for(int i=2;i<=n;i+=2){
            if(i!=4){
                cout<<i<<" ";
            }
        }
        cout<<4<<" "<<5<<" ";
        for(int i=1;i<=n;i+=2){
            if(i!=5){
                cout<<i<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}