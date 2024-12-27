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
        int n,k;
        cin>>n>>k;

        string s;
        cin>>s;

        int start=k;
        int end=n-k;
        int l=0,r=0;
        rep(i,0,n){
            if(s[i]=='0') r=i;
            
        }
        per(i,n-1,0){
            if(s[i]=='0') l=i;
        }
        ll c=count(s.begin(),s.end(),'1');
        rep(k,1,(n/2)+1){
            if(c>(n-k)) cout<<"0 ";
            else{
                r-=k;
                cout<<(r-l+k)/k<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}