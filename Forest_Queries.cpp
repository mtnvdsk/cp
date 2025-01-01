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

bool grid[1001][1001];
int dp[1001][1001];

void build_dp(int n, int m)
{
    dp[0][0] = dp[1][0] = dp[0][1] = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
            dp[i][j] = grid[i][j] + dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1];
    }
}

int getDP(int x, int y)
{
    return dp[x][y];
}

int query(int x1, int y1, int x2, int y2)
{
    return getDP(x2,y2) - getDP(x2,y1-1) - getDP(x1-1,y2) + getDP(x1-1,y1-1);
}

int main() {
    int n,q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            char ch;
            cin >> ch;
            if(ch == '*')
                grid[i][j] = 1;
            else grid[i][j] = 0;
        }
    }
    build_dp(n,n);
    while(q--)
    {
            int x1,x2,y1,y2;
            cin >> x1 >> y1 >> x2 >> y2;
            cout << query(x1,y1,x2,y2) << '\n';
    }
    return 0;
}