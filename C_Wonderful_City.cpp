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
const long long INF=1e18;

long long horz(int n, vector<int> &a, vector<vector<int>> &h){
    vector<vector<long long>> dp(n, vector<long long>(2, INF));
    dp[0][0] = 0;
    dp[0][1] = a[0];
    for(int i = 1; i < n; i++){
        for(int x = 0; x < 2; x++){
            for(int y = 0; y < 2; y++){
                bool ok = true;
                for(int j = 0; j < n; j++){
                    if(h[i-1][j] + y == h[i][j] + x){
                        ok = false;
                        break;
                    }
                }
                if(ok){
                    if(x == 0){
                        dp[i][x] = min(dp[i-1][y], dp[i][x]);
                    }
                    else{
                        dp[i][x] = min(dp[i][x], dp[i-1][y] + a[i]);
                    }
                }
            }
        }
    }
    return min(dp[n-1][0], dp[n-1][1]);
}

void transpose(vector<vector<int>> &h, int n){
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            swap(h[i][j], h[j][i]);
        }
    }
}

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>> h(n, vector<int>(n));
        vector<int> a(n), b(n);
        rep(i,0,n){
            rep(j,0,n){
                cin>>h[i][j];
            }
        }
        rep(i,0,n) cin>>a[i];
        rep(i,0,n) cin>>b[i];
        long long hor = horz(n, a, h);
        transpose(h, n);
        long long ver = horz(n, b, h);
        long long total = hor + ver;
        if(total >= INF){
            cout << -1 << endl;
        }
        else cout << total << endl;
    }   
    return 0;
}