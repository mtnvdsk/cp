#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> mp(n);
    int total_width = 0;
    multiset<int> heights;

    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        mp[i] = {x, y};
        total_width += x;
        heights.insert(y);
    }

    for (int i = 0; i < n; i++)
    {
        int width = total_width - mp[i].first;
        heights.erase(heights.find(mp[i].second));
        int height = *heights.rbegin(); 
        cout << (width * height) << " ";
        heights.insert(mp[i].second); 
    }
    cout << endl;
    return 0;
}
