#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;  // Reading the number of test cases
    while (t--) {
        int l, r;
        cin >> l >> r;  // Reading the range [l, r]

        // Limit the range of candidates to 30 from both ends.
        vector<int> candidates;
        
        // Add the first 30 numbers starting from l (or up to r if less than 30)
        for (int i = l; i < min(l + 30, r); ++i) {
            candidates.push_back(i);
        }

        // Add the last 30 numbers ending at r (or starting from l+1 if less than 30)
        for (int i = max(r - 30 + 1, l + 1); i <= r; ++i) {
            candidates.push_back(i);
        }

        // Sort the candidates and remove duplicates
        sort(candidates.begin(), candidates.end());
        candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());

        int max_xor_sum = -1;
        int best_a = -1, best_b = -1, best_c = -1;

        // Iterate through all triplets of candidates
        for (size_t i = 0; i < candidates.size(); ++i) {
            for (size_t j = i + 1; j < candidates.size(); ++j) {
                for (size_t k = j + 1; k < candidates.size(); ++k) {
                    int a = candidates[i], b = candidates[j], c = candidates[k];
                    int xor_sum = (a ^ b) + (b ^ c) + (a ^ c);
                    if (xor_sum > max_xor_sum) {
                        max_xor_sum = xor_sum;
                        best_a = a;
                        best_b = b;
                        best_c = c;
                    }
                }
            }
        }

        // Output the result for the current test case
        cout << best_a << " " << best_b << " " << best_c << endl;
    }
    return 0;
}
