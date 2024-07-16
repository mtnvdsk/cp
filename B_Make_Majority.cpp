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
        string s;
        cin>>n;
        cin>>s;
        int c0=0,c1=0;

        string t;
        rep(i,0,n){
            if(s[i]=='0'){
                while(i<n && s[i]!='1') i++;
                t+='0';
            }
            if(s[i]=='1') t+='1';
        }
        s=t;
        rep(i,0,s.size()){
            if(s[i]=='0') c0++;
            else c1++;
        }
        if(c1==c0) cout<<"NO"<<endl;
        else if(c1>c0) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}