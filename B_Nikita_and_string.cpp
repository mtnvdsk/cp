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

signed main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
    
    int t = 1;
    //cin >> t;
    while(t--) {
        string s;
        cin >> s;
        s="*"+s;
        int n = s.size();

        vector<int> l(n + 1, 0);
        vector<int> y(n + 1, 0);
        
        rep(i,1,n+1){
            l[i]=l[i-1]+(s[i]=='a'?1:0);
            y[i]=y[i-1]+(s[i]=='b'?1:0);
        }

        int ans=0;
        rep(i,0,n+1){
            rep(j,i,n+1){
                int temp=(l[n]-l[j])+(y[j]-y[i])+l[i];
                ans=max(ans,temp);
            }
        }
        cout<<ans<<endl;
    }
    
    return 0;
}
