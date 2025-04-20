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
        int n;
        cin >> n;
        
        int s = 0, sum_xy = 0;
        
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            
            s ^= x;
            sum_xy ^= (x + y);
        }
        
        int t = sum_xy - s;
        
        cout << s << " " << t << endl;
    }
    
    return 0;
}
