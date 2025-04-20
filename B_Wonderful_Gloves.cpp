//BY: tardum
#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = a; i > b; i--)
#define all(vec) vec.begin(), vec.end()
#define endl '\n'
typedef long long ll;
const int N = 1e3+5;
int main() {
    int t;
    cin >> t; 
    
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        vector<long long> left(n), right(n);
        for (int i = 0; i < n; i++) {
            cin >> left[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> right[i];
        }
        
        vector<long long> min_pairs(n), max_pairs(n);
        for (int i = 0; i < n; i++) {
            min_pairs[i] = min(left[i], right[i]);
            max_pairs[i] = max(left[i], right[i]);
        }
        long long total_gloves = 0;
        for (int i = 0; i < n; i++) {
            total_gloves += max_pairs[i];
        }
        sort(min_pairs.rbegin(), min_pairs.rend());
        
        long long result = total_gloves;
        for (int i = 0; i < k - 1; i++) {
            result += min_pairs[i];
        }
        
        cout << result+1 << endl;
    }
    
    return 0;
}
