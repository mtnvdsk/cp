#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to check if a segment is stable
bool isStable(const vector<int>& segment) {
    if (segment.size() < 3) return true; // A segment with less than 3 elements is always stable.

    vector<int> sortedSegment = segment;
    sort(sortedSegment.begin(), sortedSegment.end());

    // Check if the sum of the two smallest elements is greater than the largest element.
    return sortedSegment[0] + sortedSegment[1] > sortedSegment.back();
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        // Sort the array to simplify partitioning checks
        vector<int> sortedA = a;
        sort(sortedA.begin(), sortedA.end());

        // Check for at least two valid partitions
        if (isStable(vector<int>(sortedA.begin(), sortedA.end() - 1)) && 
            isStable(vector<int>(sortedA.end() - 1, sortedA.end()))) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}