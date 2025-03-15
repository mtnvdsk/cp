#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class UnionFind {
public:
    unordered_map<ll, ll> parent, rank, maxFloor;
    ll find(ll x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    void unite(ll x, ll y) {
        ll rootX = find(x);
        ll rootY = find(y);

        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
                maxFloor[rootX] = max(maxFloor[rootX], maxFloor[rootY]);
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
                maxFloor[rootY] = max(maxFloor[rootX], maxFloor[rootY]);
            } else {
                parent[rootY] = rootX;
                maxFloor[rootX] = max(maxFloor[rootX], maxFloor[rootY]);
                rank[rootX]++;
            }
        }
    }
    void addFloor(ll floor) {
        if (parent.find(floor) == parent.end()) {
            parent[floor] = floor;
            rank[floor] = 0;
            maxFloor[floor] = floor;
        }
    }
    ll getMaxFloor(ll floor) {
        return maxFloor[find(floor)];
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    UnionFind uf;
    for (int i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        uf.addFloor(a);
        uf.addFloor(b);
        uf.unite(a, b);
    }
    if (uf.parent.find(1) != uf.parent.end()) {
        cout << uf.getMaxFloor(1) << endl;
    } else {
        cout << 1 << endl; 
    }

    return 0;
}
