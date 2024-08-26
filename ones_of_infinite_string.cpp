//BY: tardum
#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
//---- Debugger ---- //
#define debarr(a,n) cout<<#a<<" : ";for(int i=0;i<n;i++) cerr<<a[i]<<" "; cerr<<endl;
#define debmat(mat,row,col) cout<<#mat<<" :\n";for(int i=0;i<row;i++) {for(int j=0;j<col;j++) cerr<<mat[i][j]<<" ";cerr<<endl;}
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
template <class S, class T>ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template <class T>ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const unordered_set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const unordered_map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const multiset<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T> void dbs(string str, T t) {cerr << str << " : " << t << "\n";}
template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(','); cerr << str.substr(0, idx) << " : " << t << ","; dbs(str.substr(idx + 1), s...);}
template <class T> void prc(T a, T b) {cerr << "["; for (T i = a; i != b; ++i) {if (i != a) cerr << ", "; cerr << *i;} cerr << "]\n";}
lli binpow(lli b,lli p,lli mod){lli ans=1;b%=mod;for(;p;p>>=1){if(p&1)ans=ans*b%mod;b=b*b%mod;}return ans;}
//----------------- //
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

string get_string(ll n){
    string ans="";
    while(n){
        if(n%2) ans+="1";
        else ans+="0";
        n/=2;
    }
    if(ans=="") ans="0";
    reverse(ans.begin(),ans.end());
    return ans;
}

ll sum_of_bits(ll x){
    ll ans=0;
    ll total=x+1;
    for(int i=0;i<60;i++){
        ll full=total/(1LL<<(i+1));
        ll rem=(total%(1LL<<(i+1)))-(1LL<<i);
        ll x=rem>0?rem:0;
        ans+=full*(1LL<<i)+x;
    }
    return ans;
}

ll kth_position(ll x,ll t){
    string temp=get_string(x);
    ll c=0;
    for(int i=0;i<temp.size();i++){
        if(temp[i]=='1') c++;
        if(c==t) return i;
    }
}

ll no_of_bits(ll x){
    ll ans=0;
    ll len=1;
    ll num=1;
    while(num<=x){
        ll temp=num*2-1;
        if(temp<=x){
            ans+=len*(temp-num+1);
            len++;
            num=temp+1;
        }
        else{
            ans+=(x-num+1)*len;
            break;
        }
    }
    return ans+1;
}

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        ll q;
        cin>>q;
        ll ans=0;
        ll l=0,r=q;
        while(l<=r){
            ll mid=(l+r)/2;
            ll x=sum_of_bits(mid);
            if(x>=q){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        int pos_in_num=q-sum_of_bits(ans-1);
        int index=kth_position(ans,pos_in_num);
        ll prev=no_of_bits(ans-1);
        ll out=prev+index;
        cout<<out<<endl;
    }   
    return 0;
}