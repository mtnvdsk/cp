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
        int a[n];
        int diff=INT_MAX;
        rep(i,0,n){
            cin>>a[i];
            if(i>0){
                diff=min(a[i]-a[i-1],diff);
            }
        }
        if(!is_sorted(a,a+n)){
            cout<<0<<endl;
        }
        else{
            cout<<diff/2+1<<endl;
        }
    }
    return 0;
}