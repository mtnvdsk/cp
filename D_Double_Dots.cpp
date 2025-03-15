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
        int n, m, a, b;
        cin >> n >> m;
        vector<vector<int>> g(n);
        for (int i = 0;i < m;i++) {
            cin >> a >> b;
            a--, b--;
            g[a].push_back(b);
            g[b].push_back(a);
        }

        vector<int>dist(n, -1);
        vector<int>preb(n, -1);
        queue<int>que;
        que.push(0);
        dist[0] = 0;
        while (!que.empty()) {
            auto v = que.front();que.pop();
            for (auto nv : g[v]) {
                if (dist[nv] == -1) {
                    dist[nv] = dist[v] + 1;
                    preb[nv] = v;
                    que.push(nv);
                }
            }
        }
        cout << "Yes" << endl;
        for (int i = 1;i < n;i++) {
            cout << preb[i]+1 << endl;
        }
    }
    return 0;
}