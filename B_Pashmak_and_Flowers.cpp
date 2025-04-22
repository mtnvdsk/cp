//BY: tardum
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define rep(i, a, b) for (long long i = a; i < b; i++)
#define per(i, a, b) for (long long i = a; i > b; i--)
#define endl '\n'

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long t=1;
    //cin>>t;
    while(t--){
        long long n;
        cin>>n;
        long long a[n];
        long long mx=0,mn=LONG_MAX;
        rep(i,0,n){
            cin>>a[i];
            mx=max(mx,a[i]);
            mn=min(mn,a[i]);
        }
        long long c=0,t=0;
        for(long long i=0;i<n;i++){
            if(a[i]==mx) c++;
            else if(a[i]==mn) t++;
        }
        cout<<(mx-mn)<<" ";
        if(mx==mn) cout<<(n*(n-1)/2)<<endl;
        else cout<<(c*t*1LL)<<endl;
    }
    return 0;
}