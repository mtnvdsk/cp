#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define PB push_back
#define MP make_pair
#define rep(i, a, b) for (int i = a; i < b; i++)

const int N = 1e3 + 5;
vector<vector<int>> graph;
int ans = 0;

void bfs(int n, int m) {
    queue<pair<int, pair<int, vector<int>>>> q;
    q.push(MP(0, MP(0, vector<int>{graph[0][0]})));
    
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second.first;
        vector<int> path = q.front().second.second;
        q.pop();

        if (x == n - 1 && y == m - 1) {
            ans++;
            continue;
        }
        int dx[] = {0, 1};
        int dy[] = {1, 0};

        for (int i = 0; i < 2; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if (find(path.begin(), path.end(), graph[nx][ny]) == path.end()) {
                    vector<int> temp(path);
                    temp.PB(graph[nx][ny]);
                    q.push(MP(nx, MP(ny, temp)));
                }
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        graph.assign(n, vector<int>(m));
        rep(i, 0, n) {
            rep(j, 0, m) cin >> graph[i][j];
        }
        bfs(n, m);
        cout << ans << endl;
    }
    return 0;
}
