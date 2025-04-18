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
const int N = 1e3 + 5;

vector<int> dp;

int rec(int n,int &ans)
{
    //cout << n << endl;
    ans=min(ans,n);
    if (n <= 0)
        return 0;
    
    if (n - 3 >= 0)
        rec(n - 3,ans);
    if (n - 5 >= 0)
        rec(n - 5,ans);
    
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        dp.assign(n + 1, -1);
        int ans=INT_MAX;
        int rem = rec(n,ans);
        cout << rem << endl;
    }
    return 0;
}
