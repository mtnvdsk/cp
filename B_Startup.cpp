//BY: tardum
#include <bits/stdc++.h>
using namespace std;
typedef long long lli;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    lli t;
    cin >> t;
    
    while (t--) {
        lli n, k;
        cin >> n >> k;
        unordered_map<lli, vector<lli>> brand_costs;
        for (lli i = 0; i < k; i++) {
            lli b, c;
            cin >> b >> c;
            brand_costs[b].push_back(c);
        }
        vector<lli> max_costs;

        for (auto &entry : brand_costs) {
            vector<lli> &costs = entry.second;
            lli sum = 0;
            for (lli i = 0; i < costs.size(); i++) {
                sum += costs[i];
            }
            
            max_costs.push_back(sum);
        }
        sort(max_costs.rbegin(), max_costs.rend());
        lli max_profit = 0;
        for (lli i = 0; i < min((lli)max_costs.size(), n); i++) {
            max_profit += max_costs[i];
        }

        cout << max_profit << endl;
    }
    
    return 0;
}
