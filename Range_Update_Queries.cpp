// BY: tardum
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
#define int long long

vector<int> tree;

void update(int node, int start, int end, int l, int r, int val) {
    // No overlap
    if (start > r || end < l) return;

    // Complete overlap
    if (start >= l && end <= r) {
        tree[node] += val;
        return;
    }

    // Partial overlap
    int mid = (start + end) / 2;
    update(2 * node, start, mid, l, r, val);
    update(2 * node + 1, mid + 1, end, l, r, val);
}

int query(int node, int start, int end, int idx) {
    // Base case: reached the leaf
    if (start == end) return tree[node];

    int mid = (start + end) / 2;
    if (idx <= mid) return tree[node] + query(2 * node, start, mid, idx);
    return tree[node] + query(2 * node + 1, mid + 1, end, idx);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    while (t--) {
        int n, q;
        cin >> n >> q;
        tree.resize(4 * n, 0); // Initialize segment tree with zeros

        // Initialize the array
        rep(i, 0, n) {
            int x;
            cin >> x;
            update(1, 0, n - 1, i, i, x); // Update each element individually
        }

        // Process queries
        while (q--) {
            int no;
            cin >> no;

            if (no == 1) { // Range update
                int a, b, u;
                cin >> a >> b >> u;
                a--, b--; // Convert to 0-based indexing
                update(1, 0, n - 1, a, b, u);

            } else if (no == 2) { // Point query
                int k;
                cin >> k;
                k--; // Convert to 0-based indexing
                cout << query(1, 0, n - 1, k) << endl;
            }
        }
    }

    return 0;
}
