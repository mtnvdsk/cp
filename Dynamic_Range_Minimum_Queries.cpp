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
const int INF=LLONG_MAX;
const int N = 1e3+5;
vector<int> tree;
void update(int node,int l,int r,int idx,int val){
    if(l==r){
        tree[node]=val;
	return;
    }
    int mid=(l+r)>>1;
    if(idx<=mid) update(2*node,l,mid,idx,val);
    else update(2*node+1,mid+1,r,idx,val);
    tree[node]=min(tree[2*node],tree[2*node+1]);
}

int query(int node,int start,int end,int l,int r){
    if(start>r || end<l) return INF;
    if(start>=l && end<=r) return tree[node];
    int mid=(start+end)>>1;
    return min(query(2*node,start,mid,l,r),query(2*node+1,mid+1,end,l,r));
}
signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;
        tree.resize(4*n);
        rep(i,0,n){
            int x;
            cin>>x;
            update(1,0,n-1,i,x);
        }
        while(q--){
            int k,l,r;
            cin>>k>>l>>r;
            if(k==2)
            cout<<query(1,0,n-1,l-1,r-1)<<endl;
            else
            update(1,0,n-1,l-1,r);
        }
    }
    return 0;
}