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

vector<int> tree;
void update(int node,int l,int r,int idx,int val){
    if(l>idx || r<idx) return;
    if(l==r){
        tree[node]=val;
        return;
    }
    int mid=(l+r)>>1;
    update(2*node,l,mid,idx,val);
    update(2*node+1,mid+1,r,idx,val);
    tree[node]=tree[2*node]^tree[2*node+1];
}
int query(int node,int l,int r,int lq,int rq){
    if(lq>r || rq<l) return 0;
    if(lq<=l && rq>=r) return tree[node];
    int mid=(l+r)>>1;
    return query(2*node,l,mid,lq,rq)^query(2*node+1,mid+1,r,lq,rq);
}

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
      int n,q;
      cin>>n>>q;
      tree.resize(4*n);
      rep(i,0,n)  {
        int x;
        cin>>x;
        update(1,0,n-1,i,x);
      }
      while(q--){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        cout<<query(1,0,n-1,a,b)<<endl;
      }
    }
    return 0;
}