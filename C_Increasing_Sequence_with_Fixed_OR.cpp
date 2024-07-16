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

// Function to convert a binary string to an integer
int todecimal(const string &s) {
    int result = 0;
    for (char c : s) {
        result = (result << 1) | (c - '0');
    }
    return result;
}

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        int binaryNum[32] = {0};
        vector<int> ans;

        int temp_n = n;
        int i = 0;
        while (temp_n > 0) {
            binaryNum[i] = temp_n % 2;
            temp_n = temp_n / 2;
            i++;
        }

        string s;
        rep(i, 0, 32) s += (binaryNum[31 - i] + '0');
        rep(i, 0, 32) {
            if (s[i] == '1') {
                string temp = s;
                temp[i] = '0';
                int t = todecimal(temp);
                ans.PB(t);
            }
        }
        ans.PB(todecimal(s));

        sort(all(ans));
        if(ans.size()==2 && ans[0]==0){
            cout<<1<<endl;
            cout<<ans[1];
        }
        else{
            cout<<ans.size()<<endl;
            rep(i, 0, ans.size()) cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
