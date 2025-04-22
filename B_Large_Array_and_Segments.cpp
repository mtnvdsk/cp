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
#define int long long
#define N 200001

signed main(){
    int t=1;
    cin>>t;
    while(t--){
        int n,k,x;
        cin>>n>>k>>x;
        vector<int> a(n);
        rep(i,0,n) cin>>a[i];
        if(accumulate(a.begin(),a.end(),0ll)*k<x){
            cout<<0<<endl;
            continue;
        }
        int l=1,r=n*k;
        while(l<=r){
            int mid=(l+r)>>1;
            int total=(n*k-mid+1)/n;
            int diff=(n*k-mid+1)%n;
            int sum=total*accumulate(a.begin(),a.end(),0ll);
            for(int i=n-diff;i<n;i++){
                sum += a[i];
            }
            if(sum<x) r=mid-1;
            else l=mid+1;
        }
        cout << r << endl;
    }
}