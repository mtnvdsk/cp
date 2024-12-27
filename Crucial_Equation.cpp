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

int gcd(int a,int b,int &x,int &y){
    if(b==0){
        x=1;
        y=0;
        return a;
    }
    int x1,y1;
    int temp=gcd(b,a%b,x1,y1);
    x=y1;
    y=x1-y1*(a/b);
    return temp;
}

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    
    int i=0;
    while(t--){
        int a,b,c;
        cin>>a>>b>>c;
        int x1,x2;
        gcd(a,b,x1,x2);
        int d=(a*x1)+(b*x2);
        if(c%d==0){
            cout<<"Case "<<++i<<": Yes"<<endl;
        }
        else{
            cout<<"Case "<<++i<<": No"<<endl;
        }
    }
    return 0;
}