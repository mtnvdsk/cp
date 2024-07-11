//BY: mtnvdsk
#include <bits/stdc++.h>
using namespace std;

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

        
        if(n==1) cout<<1<<endl;
        else if(n%2) cout<<-1<<endl;
        else{
            int a[n];
            iota(a,a+n,1);
            for(int i=0;i<n;i+=2) swap(a[i],a[i+1]);
            for(auto i:a) cout<<i<<" ";
            cout<<endl;
        }
    }
    return 0;
}