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
        int n,m;
        cin>>n>>m;
        vector<bool> is_prime(n+1,true);
        is_prime[0]=is_prime[1]=false;
        for(int i=2;i*i<=n;i++){
            if(is_prime[i] && i*i<=n){
                for(int j=i*i;j<=n;j+=i){
                    is_prime[j]=false;
                    div[j].PB(i);
                }
            }   
        }
        int e=0;
        vector<bool> on;
        rep(i,0,m){
            char sign;
            int num;
            cin>>sign>>num;
            if(sign=='-'){
                if(num%2==0 && e!=0){
                    cout<<"conflict with "<<e<<endl;
                }
                else if(is_prime[num] && on[num]){
                    cout<<"Already on"<<endl;
                }
                else if(is_prime[num]){
                    on[num]=1;
                    cout<<"Success"<<endl;
                }
                else{
                    on[num]=1;
                    e=num;
                }
            }
            else{
                if(on[num]){
                    cout<<"Success"<<endl;
                    on[num]=0;
                }
                else{
                    cout<<"Already off"<<endl;
                }
            }
        }
    }
    return 0;
}