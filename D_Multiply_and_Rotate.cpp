#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int bfs(int a, int N) {
    unordered_map<int, int> dist;
    queue<int> q;
    q.push(1);
    dist[1] = 0;
    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        int steps = dist[curr];
        if (curr == N) {
            return steps;
        }
        ll next = 1LL * curr * a;
        if (next < 10 * N && dist.find(next) == dist.end()) {
            dist[next] = steps + 1;
            q.push(next);
        }
        if (curr >= 10 && curr % 10 != 0) {
            string s = to_string(curr);
            rotate(s.begin(), s.end() - 1, s.end());
            int rotated = stoi(s);

            if (dist.find(rotated) == dist.end()) {
                dist[rotated] = steps + 1;
                q.push(rotated);
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int a, N;
    cin >> a >> N;

    int result = bfs(a, N);
    cout << result << '\n';

    return 0;
}
