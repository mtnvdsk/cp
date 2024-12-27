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
const int N = 100000;

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int x=n;
        int sum=0;
        vector<int> d;
        vector<int> mp(N,0);
        while(x>0){
            sum+=(x%10);
            d.push_back(x%10);
            mp[x%10]++;
            x/=10;
        }
        if((sum%9)==0) cout<<"YES"<<endl;
        else{
            bool f=false;
            if(find(d.begin(), d.end(), 2) != d.end()){
                for(int i=1;i<=mp[2];i++){
                    if((sum + 2*(i)) % 9 == 0){
                        f=true;
                        break;
                    }
                }
            }
            else if(find(d.begin(), d.end(), 3) != d.end()){
                if((sum + 6*(mp[3])) % 9 == 0) f = true;
                for(int i=1;i<=mp[3];i++){
                    if((sum + 6*(i)) % 9 == 0){
                        f=true;
                        break;
                    }
                }
            }
            else if(find(d.begin(), d.end(), 2) != d.end() && find(d.begin(), d.end(), 3) != d.end()){
                for(int i=1;i<=mp[3];i++){
                    for(int j=1;j<=mp[2];j++)
                        if((sum + 2*(j) + 6*(i))%9==0){
                            f=true;
                            break;
                        }
                }
            }
            if(f) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
    return 0;
}


//333 333 333 333