#include <bits/stdc++.h>
#define Z c.begin()
using namespace std;
int main(){
    int t,n,l,r,i,a[200000];
    cin>>t;
    while(t--){
        cin>>n>>l>>r;
        l--;
        for(i=0;i<n;i++){
            cin>>a[i];
        }
        vector<int>c(a+l,a+n);
        sort(a,a+r);
        sort(Z,c.end());
        cout<<min(accumulate(a,a+r-l,0ll),accumulate(Z,r-l+Z,0ll))<<' ';
    }
}