#include <bits/stdc++.h>
using namespace std;

const int N = 1000;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    int n, k;
    cin >> n >> k;
    vector<bool> is_prime(N + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= N; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= N; j += i) {
                is_prime[j] = false;
            }
        }
    }
    vector<int> primes;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
    int count = 0;
    for (size_t i = 0; i + 1 < primes.size(); i++) {
        int candidate = primes[i] + primes[i + 1] + 1;
        if (candidate <= n && is_prime[candidate]) {
            count++;
        }
    }
    if (count >= k) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
