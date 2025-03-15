//BY: tardum
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

class UnionFind {
private:
    vector<int> parent, size;
    int components;
    int largest;

public:
    UnionFind(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        components = n;
        largest = 1;
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (size[rootX] < size[rootY]) {
                swap(rootX, rootY);
            }
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
            size[rootY] = 0;
            components--;
            largest = max(largest, size[rootX]);
        }
    }

    int getComponents() const {
        return components;
    }

    int getLargestComponent() const {
        return largest;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    UnionFind uf(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        uf.unite(u, v);

        cout << uf.getComponents() << " " << uf.getLargestComponent() << endl;
    }

    return 0;
}
