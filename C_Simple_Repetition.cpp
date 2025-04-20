// BY: tardum
#include <bits/stdc++.h>
#include <cstdint>
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
#define long long int;
const int N = 1e3 + 5;

bool check(int n)
{
    if (n == 1)
        return true;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return true;
    }
    return false;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int x, k;
        cin >> x >> k;
        

        if (k >1 && x>1)
        {
            cout << "NO" << endl;
        }
        else if(k==1){
            cout<<((check(x))?"NO":"YES")<<endl;
        }
        else{
            cout<<((k==2)?"YES":"NO")<<endl;
        }
    }
    return 0;
}