#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

// Helper function for binary search to count fixed values within a range
int countFixedValuesInRange(const vector<int>& fixedValues, int low, int high) {
    return upper_bound(fixedValues.begin(), fixedValues.end(), high) -
           lower_bound(fixedValues.begin(), fixedValues.end(), low);
}

void solve() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<pair<int, int>> ranges(n);
        vector<int> fixedValues;
        vector<int> result(n, 0);

        for (int i = 0; i < n; ++i) {
            cin >> ranges[i].first >> ranges[i].second;
            if (ranges[i].first == ranges[i].second) {
                // Fixed value
                fixedValues.push_back(ranges[i].first);
            }
        }

        // Sort the fixed values for binary search
        sort(fixedValues.begin(), fixedValues.end());

        for (int i = 0; i < n; ++i) {
            int li = ranges[i].first;
            int ri = ranges[i].second;

            // Count fixed values in the range [li, ri]
            int fixedCount = countFixedValuesInRange(fixedValues, li, ri);

            // Check if the impression can be unique
            int rangeSize = ri - li + 1;
            if (fixedCount < rangeSize) {
                result[i] = 1;
            }
        }

        // Output the result as a binary string
        for (int bit : result) {
            cout << bit;
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
