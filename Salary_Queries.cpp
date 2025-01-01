//BY: tardum
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
#define int long long
const int N = 1e3+5;

struct node{
    node *left,*right;
    int sum;
    node(): left(NULL),right(NULL),sum(0){}
    void extend(){
        if(!left){
            left=new node();
            right=new node();
        }        
    }
    void update(int l,int r,int val,int idx){
        if(l==r){
            sum+=val;
            return;
        }
        extend();
        int mid=(l+r)>>1;
        if(idx<=mid) left->update(l,mid,val,idx);
        else right->update(mid+1,r,val,idx);
        sum=left->sum+right->sum;
    }
    int query(int l,int r,int qs,int qe){
        if(r<qs || qe<l) return 0;
        if(qs<=l && qe>=r) return sum;
        extend();
        int mid=(l+r)>>1;
        return left->query(l,mid,qs,qe)+right->query(mid+1,r,qs,qe);
    }
};

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    node* rmq = new node();
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin >> a[i];
        rmq->update(0, 1e9+1,1,a[i]);
    }
    while(q--) {
        char qt;
        cin >> qt;
        if(qt == '?') { //query
            int a, b; cin >> a >> b;
            cout << rmq->query(0, 1e9+1,a, b) << "\n";
        } else { //update
            int k, x; cin >> k >> x;
            rmq->update(0, 1e9+1,-1,a[k-1]);
            rmq->update(0, 1e9+1,1,x);
            a[k-1] = x;
        }
    }
    return 0;
}