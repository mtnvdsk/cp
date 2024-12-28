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
        vector<int> b(n,-1),a(n);
        vector<bool> w(n,false);
        rep(i,0,n){
            cin>>a[i];
            --a[i];
            if(!w[a[i]]){
                b[i]=a[i];
                w[a[i]]=true;
            }
        }
        int t=0;
        rep(i,0,n){
            if(b[i]==-1){
                while(w[t]){
                    t++;
                }
                b[i]=t;
                w[t]=true;
            }
            
        }
        for(auto i:b) cout<<i+1<<" ";
        cout<<"\n";
    }
    return 0;
}