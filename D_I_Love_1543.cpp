#include <bits/stdc++.h>
using namespace std;

// Helper function to extract the layer from the grid in a clockwise direction
vector<int> get_layer(const vector<vector<int>>& carpet, int layer, int n, int m) {
    vector<int> result;
    int start_row = layer, start_col = layer;
    int end_row = n - layer - 1, end_col = m - layer - 1;
    
    // Top row (left to right)
    for (int j = start_col; j <= end_col; j++) {
        result.push_back(carpet[start_row][j]);
    }
    // Right column (top to bottom)
    for (int i = start_row + 1; i <= end_row; i++) {
        result.push_back(carpet[i][end_col]);
    }
    // Bottom row (right to left)
    if (end_row > start_row) {
        for (int j = end_col - 1; j >= start_col; j--) {
            result.push_back(carpet[end_row][j]);
        }
    }
    // Left column (bottom to top)
    if (end_col > start_col) {
        for (int i = end_row - 1; i > start_row; i--) {
            result.push_back(carpet[i][start_col]);
        }
    }
    
    return result;
}

// Function to count occurrences of "1543" in a vector of digits
int count_1543(const vector<int>& layer) {
    int count = 0;
    for (size_t i = 0; i + 3 < layer.size(); i++) {
        if (layer[i] == 1 && layer[i + 1] == 5 && layer[i + 2] == 4 && layer[i + 3] == 3) {
            count++;
        }
    }
    return count;
}

void solve() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> carpet(n, vector<int>(m));
    
    // Read the carpet grid
    for (int i = 0; i < n; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < m; j++) {
            carpet[i][j] = row[j] - '0';
        }
    }
    
    int total_count = 0;
    
    // Traverse each layer
    for (int layer = 0; layer < min(n, m) / 2; layer++) {
        vector<int> current_layer = get_layer(carpet, layer, n, m);
        total_count += count_1543(current_layer);
    }
    
    cout << total_count << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
