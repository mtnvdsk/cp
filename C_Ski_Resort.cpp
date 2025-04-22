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
        long long n,k,q;
        cin>>n>>k>>q;
        vector<int> a(n);
        long long c=0;
        long long ans=0;
        rep(i,0,n){
            cin>>a[i];
            if(a[i]<=q){
                c++;
            }
            else c = 0;
            if(c>=k){
                ans+=(c-k+1);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}