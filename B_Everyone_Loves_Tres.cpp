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
        int n;
        cin>>n;
        if(n == 1 || n == 3){
			cout << "-1\n";
		}else if(n%2 == 0){
			rep(i,0,n-2){
				cout << "3";
			}
			cout << "66\n";
		}else{
			for(int i = 0; i<n-5; i++){
				cout << "3";
			}
			cout << "36366\n";
		}
    }
    return 0;
}