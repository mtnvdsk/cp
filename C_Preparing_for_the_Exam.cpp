#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;

        vector<int> a(m);
        for (int i = 0; i < m; ++i) {
            cin >> a[i];
        }

        set<int> knownQuestions;
        for (int i = 0; i < k; ++i) {
            int q;
            cin >> q;
            knownQuestions.insert(q);
        }

        string result(m, '0');

        if (k == n) {
            result = string(m, '1');
        } else if (k < n - 1) {
            result = string(m, '0');
        } else {
            int unknownQuestion = 0;
            for (int i = 1; i <= n; ++i) {
                if (knownQuestions.find(i) == knownQuestions.end()) {
                    unknownQuestion = i;
                    break;
                }
            }

            for (int i = 0; i < m; ++i) {
                if (a[i] == unknownQuestion) {
                    result[i] = '1';
                }
            }
        }

        cout << result << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
