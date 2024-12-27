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
#define int long long
const int N = 1e3+5;

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        int n;
        cin>>n;
        int s=n*(n+1)/2;
        vector<int> a,b;
        if(s%2==0){
            cout<<"YES"<<endl;
            int ps=s/2;
            vector<int> a,b,vis(n+1,0);
            int max_ele=n;
            int set_s=0;
            while(set_s<s/2){
                int remain=s/2-set_s;
                if(remain>max_ele){
                    a.push_back(max_ele);
                    vis[max_ele]=1;
                    set_s+=max_ele;
                    max_ele--;
                }
                else{
                    a.push_back(remain);
                    vis[remain]=1;
                    set_s+=remain;
                }
            }
            cout<<a.size()<<endl;
            for(int i=1;i<=n;i++){
                if(vis[i]==0) b.push_back(i);
            }
            for(auto i:a) cout<<i<<" ";
            cout<<endl;
            cout<<b.size()<<endl;
            for(auto i:b) cout<<i<<" ";
            cout<<endl;
        }
        else cout<<"NO"<<endl;
    }
    return 0;
}