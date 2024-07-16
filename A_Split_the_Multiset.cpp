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
        int n,k;
        cin>>n>>k;

        deque<int> m;
        int count=0;
        rep(i,0,n) m.PB(1);
        while(m.size() != 1){
            int temp=0;
            rep(i,0,k){
                if(m.empty()) break;
                temp+=m.front();
                m.pop_front();
            }
            m.push_back(temp);
            count++;
        }
        cout<<count<<endl;
    }
    return 0;
}