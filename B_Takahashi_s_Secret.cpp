#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    int n, x;
    cin >> n >> x;

    vector<int> A(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> A[i];
    }

    vector<bool> visited(n + 1, false);
    queue<int> q;
    q.push(x);
    visited[x] = true;

    int count = 0;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        count++;
        int next = A[curr];
        if (!visited[next]) {
            visited[next] = true;
            q.push(next);
        }
    }

    cout << count << endl;
    return 0;
}
