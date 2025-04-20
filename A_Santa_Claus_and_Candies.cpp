#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> result;
    int sum = 0, i = 1;

    while (sum + i <= n) {
        result.push_back(i);
        sum += i;
        i++;
    }
    result.back() += n - sum;

    cout << result.size() << endl;
    for (int candy : result) {
        cout << candy << " ";
    }
    cout << endl;

    return 0;
}
