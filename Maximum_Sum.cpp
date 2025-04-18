#include <bits/stdc++.h>
using namespace std;

struct Node {
    int first_max, second_max;
};

const int MAXN = 1e5 + 5;
Node seg[4 * MAXN];
int A[MAXN];

Node merge(Node left, Node right) {
    vector<int> vals = {left.first_max, left.second_max, right.first_max, right.second_max};
    sort(vals.begin(), vals.end(), greater<int>());
    return {vals[0], vals[1]};
}

void build(int node, int l, int r) {
    if (l == r) {
        seg[node] = {A[l], INT_MIN};
        return;
    }
    int mid = (l + r) / 2;
    build(2 * node, l, mid);
    build(2 * node + 1, mid + 1, r);
    seg[node] = merge(seg[2 * node], seg[2 * node + 1]);
}

void update(int node, int l, int r, int idx, int val) {
    if (l == r) {
        seg[node] = {val, INT_MIN};
        return;
    }
    int mid = (l + r) / 2;
    if (idx <= mid)
        update(2 * node, l, mid, idx, val);
    else
        update(2 * node + 1, mid + 1, r, idx, val);
    seg[node] = merge(seg[2 * node], seg[2 * node + 1]);
}

Node query(int node, int l, int r, int ql, int qr) {
    if (qr < l || r < ql) return {INT_MIN, INT_MIN};
    if (ql <= l && r <= qr) return seg[node];
    int mid = (l + r) / 2;
    Node left = query(2 * node, l, mid, ql, qr);
    Node right = query(2 * node + 1, mid + 1, r, ql, qr);
    return merge(left, right);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];

    build(1, 0, N - 1);

    int Q;
    cin >> Q;
    while (Q--) {
        char op;
        int x, y;
        cin >> op >> x >> y;
        if (op == 'U') {
            update(1, 0, N - 1, x - 1, y);
        } else {
            Node res = query(1, 0, N - 1, x - 1, y - 1);
            cout << (res.first_max + res.second_max) << '\n';
        }
    }

    return 0;
}
