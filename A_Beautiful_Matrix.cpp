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
    //cin>>t;
    while(t--){
        int start=0,end=0;;

        int a[5][5];
        rep(i,0,5){
            rep(j,0,5){
                cin>>a[i][j];
                if(a[i][j]==1){
                    start=i+1;
                    end=j+1;
                }
            }
        }
        int ans=abs(3-start)+abs(3-end);
        cout<<ans<<endl;
    }
    return 0;
}