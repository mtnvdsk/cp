// BY: tardum
#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

#define PB push_back
#define rep(i, a, b) for (int i = a; i < b; i++)
#define endl '\n'
const int MOD = 1e9 + 7;

vector<vector<int>> graph;
vector<int> dist;
vector<int> cnt;

void bfs(int n) {
    queue<int> q;
    dist.assign(n, -1);
    cnt.assign(n, 0);

    dist[0] = 0;
    cnt[0] = 1;
    q.push(0);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (auto neigh : graph[node]) {
            if (dist[neigh] == -1) {
                dist[neigh] = dist[node] + 1;
                q.push(neigh);
                cnt[neigh] = cnt[node];
            } else if (dist[neigh] == dist[node] + 1) {
                cnt[neigh] = (cnt[neigh] + cnt[node]) % MOD; 
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    graph.resize(n);
    rep(i, 0, m) {
        int u, v;
        cin >> u >> v;
        u--; v--; 
        graph[u].PB(v);
        graph[v].PB(u);
    }

    bfs(n);

    cout << cnt[n - 1] << endl;
    return 0;
}
