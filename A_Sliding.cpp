#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m, r, c;
        cin >> n >> m >> r >> c;

        // Calculate the Manhattan distance to each corner and find the maximum
        lli dist1 = abs(r - 1) + abs(c - 1);
        lli dist2 = abs(r - 1) + abs(c - m);
        lli dist3 = abs(r - n) + abs(c - 1);
        lli dist4 = abs(r - n) + abs(c - m);

        // Maximum distance from the four corners
        lli result = max({dist1, dist2, dist3, dist4});

        cout << result << endl;
    }
    return 0;
}
