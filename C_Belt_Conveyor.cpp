#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int h, w;
    cin >> h >> w;

    vector<vector<char>> grid(h + 1, vector<char>(w + 1));
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            cin >> grid[i][j];
        }
    }
    map<char, pii> directions = {
        {'U', {-1, 0}},
        {'D', {1, 0}},
        {'L', {0, -1}},
        {'R', {0, 1}}
    };

    vector<vector<bool>> visited(h + 1, vector<bool>(w + 1, false));

    int x = 1, y = 1;
    while (true) {
        if (visited[x][y]) {
            cout << -1 << endl;
            return 0;
        }

        visited[x][y] = true;

        char move = grid[x][y];
        int nx = x + directions[move].first;
        int ny = y + directions[move].second;

        if (nx < 1 || ny < 1 || nx > h || ny > w) {
            cout << x << " " << y << endl;
            return 0;
        }

        x = nx;
        y = ny;
    }

    return 0;
}
