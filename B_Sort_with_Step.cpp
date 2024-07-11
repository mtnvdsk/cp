//BY: mtnvdsk
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
    ll t=1;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> v(n);
        rep(i,0,n){
            cin>>v[i];
        }

        vector<set<int>> sorted;
        vector<set<int>> a;
        
        rep(i,0,k){
            set<int> x,y;
            for(int j=i;j<n;j+=k){
                x.insert(v[j]);
                y.insert(j+1);
            }
            sorted.PB(y);
            a.PB(x);
        }

        int ans=0;
        for(int i=0;i<k;i++){
            for(auto j:sorted[i]){
                if(a[i].find(j)==a[i].end()) ans++;
            }
        }

        if(ans==0) cout<<0<<endl;
        else if(ans==2) cout<<1<<endl;
        else cout<<-1<<endl;

    }
    return 0;
}