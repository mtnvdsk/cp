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
        vector<int> r(n+1),d(n+1);
        for(int i=1;i<=n;i++)
        {
            cin>>r[i];
            d[r[i]]++;
        }
        set<pair<int,int> > s;
        for(int i=1;i<=n;i++)
            s.insert({d[i],i});
        int ans=2;
        queue<int> q;
        while(!s.empty()&&(*s.begin()).first==0)
        {
            while(!s.empty()&&(*s.begin()).first==0)
            {
                int k=(*s.begin()).second;
                auto it=s.find({d[r[k]],r[k]});
                d[r[k]]--;
                if(it!=s.end())
                {
                    s.erase(it);
                    q.push(r[k]);
                }
                s.erase(s.begin());
            }
            while(!q.empty())
                s.insert({d[q.front()],q.front()}),q.pop();
            ans++;
        }
        cout<<ans<<'\n';
    }
    return 0;
}