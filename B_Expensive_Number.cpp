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

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        string s;
        cin >> s;
        int n = s.size();
        bool met_positive = false;
        int cnt_zero = 0;
        
        for (auto i = n - 1; i >= 0; --i) {
            if (s[i] != '0') {
                met_positive = true;
            } else if (met_positive) {
                cnt_zero++;
            }
        }
        
        cout << n - (cnt_zero + 1) << '\n';
    }
    return 0;
}