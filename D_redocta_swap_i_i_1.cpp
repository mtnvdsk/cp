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
    //cin>>t;
    while(t--){
        string s;
        cin>>s;
        map<string,int> mp;
        mp[s]=0;
        queue<string> q;
        q.push(s);
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            if(it=="atcoder"){
                cout<<mp[it]<<endl;
            }
            
            for(int i=1;i<7;i++){
                string curr=it;
                swap(curr[i-1],curr[i]);
                if(mp.find(curr)==mp.end()){
                    mp[curr]=mp[it]+1;
                    q.push(curr);
                }
            }
        }
    }
    return 0;
}