#include <iostream>
#include <algorithm>
using namespace std;

// Function to compute the minimum value of x after n OPER 1 and m OPER 2
long long computeMin(long long x, long long n, long long m) {
    // Apply all n floor operations
    for (long long i = 0; i < n; ++i) {
        x = x / 2;
        if (x == 0) break; // Early termination if x becomes 0
    }
    // Apply all m ceiling operations
    for (long long i = 0; i < m; ++i) {
        x = (x + 1) / 2;
        if (x == 0) break; // Early termination if x becomes 0
    }
    return x;
}

// Function to compute the maximum value of x after n OPER 1 and m OPER 2
long long computeMax(long long x, long long n, long long m) {
    // Apply all m ceiling operations
    for (long long i = 0; i < m; ++i) {
        x = (x + 1) / 2;
        if (x == 0) break; // Early termination if x becomes 0
    }
    // Apply all n floor operations
    for (long long i = 0; i < n; ++i) {
        x = x / 2;
        if (x == 0) break; // Early termination if x becomes 0
    }
    return x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long x, n, m;
        cin >> x >> n >> m;
        
        // Early termination if n + m is large enough to reduce x to 0
        if (n + m >= 60) {
            cout << "0 0\n";
            continue;
        }
        
        long long minVal = computeMin(x, n, m);
        long long maxVal = computeMax(x, n, m);
        
        cout << minVal << " " << maxVal << "\n";
    }

    return 0;
}