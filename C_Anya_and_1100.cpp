//BY: tardum
#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    string s;
    cin >> s;
    int q;
    cin >> q;
    set<int> pos_1100;
    auto is_1100 = [&](int i) {
        return i >= 0 && i + 3 < s.size() && s.substr(i, 4) == "1100";
    };
    for (int i = 0; i + 3 < s.size(); ++i) {
        if (is_1100(i)) {
            pos_1100.insert(i);
        }
    }

    while (q--) {
        int i, v;
        cin >> i >> v;
        --i;
        for (int j = i - 3; j <= i; ++j) {
            if (is_1100(j)) {
                pos_1100.erase(j);
            }
        }
        s[i] = '0' + v;
        for (int j = i - 3; j <= i; ++j) {
            if (is_1100(j)) {
                pos_1100.insert(j);
            }
        }
        if (!pos_1100.empty()) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
