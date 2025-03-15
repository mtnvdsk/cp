#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Extended Euclidean Algorithm
ll gcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll g = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}
bool find_any_solution(ll a, ll b, ll c, ll &x0, ll &y0) {
    ll g = gcd(abs(a), abs(b), x0, y0);
    if (c % g != 0) return false;
    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll X, Y;
    cin >> X >> Y;

    ll A, B;
    if (find_any_solution(X, -Y, 2, B, A)) { 
        if (abs(A) <= 1e18 && abs(B) <= 1e18) {
            cout << A << " " << B << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
