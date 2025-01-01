#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> tree;
void buildTree(vector<ll> &a, int node, int start, int end) {
    if (start == end) {
        tree[node] = a[start];
    } else {
        int mid = (start + end) / 2;
        buildTree(a, 2 * node, start, mid);
        buildTree(a, 2 * node + 1, mid + 1, end);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
}

ll query(int node, int start, int end, int l, int r) {
    if (start > r || end < l) return 0; 
    if (start >= l && end <= r) return tree[node]; 
    int mid = (start + end) / 2;
    return query(2 * node, start, mid, l, r) + query(2 * node + 1, mid + 1, end, l, r);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    tree.resize(4 * n);

    buildTree(a, 1, 0, n - 1);
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        cout << query(1, 0, n - 1, l, r) << endl;
    }

    return 0;
}
