#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        vector<int> a(n);
        unordered_map<int, int> freq;
        
        // Input array and frequency map
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            freq[a[i]]++;
        }
        
        // Get the frequencies of each unique number
        vector<int> frequencies;
        for (const auto& entry : freq) {
            frequencies.push_back(entry.second);
        }
        
        // Sort frequencies in ascending order
        sort(frequencies.begin(), frequencies.end());
        
        int remaining_replacements = k;
        int distinct_elements = frequencies.size();
        
        // Try to reduce the number of distinct elements by replacing the least frequent ones
        for (int i = 0; i < frequencies.size(); i++) {
            if (remaining_replacements >= frequencies[i]) {
                remaining_replacements -= frequencies[i];
                distinct_elements--;
            } else {
                break;
            }
        }
        
        // Output the result: the minimum possible value of f(a)
        cout << distinct_elements << endl;
    }
    
    return 0;
}
