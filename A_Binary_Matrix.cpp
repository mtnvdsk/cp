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
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    
    for (int i = 0; i < n; ++i) {
        string row;
        cin >> row;
        for (int j = 0; j < m; ++j) {
            matrix[i][j] = row[j] - '0';
        }
    }
    
    vector<int> rowXor(n, 0), colXor(m, 0);
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            rowXor[i] ^= matrix[i][j];
            colXor[j] ^= matrix[i][j];
        }
    }
    
    int rowFixes = 0, colFixes = 0;
    for (int i = 0; i < n; ++i) {
        if (rowXor[i] != 0) rowFixes++;
    }
    for (int j = 0; j < m; ++j) {
        if (colXor[j] != 0) colFixes++;
    }
    
    cout << max(rowFixes, colFixes) << "\n";
}

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}