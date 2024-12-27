#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;

    // Sieve of Eratosthenes
    vector<int> prime_divisors(n + 1, 0);
    for (int i = 2; i <= n; i++) {
        if (prime_divisors[i] == 0) { // i is prime
            for (int j = i; j <= n; j += i) {
                prime_divisors[j]++;
            }
        }
    }

    // Count numbers with exactly 2 distinct prime divisors
    int count = 0;
    for (int i = 2; i <= n; i++) {
        if (prime_divisors[i] == 2) {
            count++;
        }
    }

    cout << count << endl;
    return 0;
}
