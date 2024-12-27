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
        int n,k;
        cin>>n>>k;
        map<int,int> a;
        int ans=0;
        rep(i,0,n){
            int temp;
            cin>>temp;
            a[temp]++;
        }
        for(int i=0;i<=n;i++){
            if(a[i]==0){
                cout<<i<<endl;
                break;
            }
            a[i+k]+=a[i]-1;
        }
    }
    return 0;
}