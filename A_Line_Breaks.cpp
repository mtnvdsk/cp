#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<string> words(n);
        for (int i = 0; i < n; i++) {
            cin >> words[i];
        }

        int ans = 0, current_length = 0;
        for (int i = 0; i < n; i++) {
            if (current_length + words[i].size() <= m) {
                current_length += words[i].size();
                ans++;
            } else {
                break;
            }
        }

        cout << ans << endl;
    }
    return 0;
}
