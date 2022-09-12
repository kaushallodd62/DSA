#include<bits/stdc++.h>
using namespace std;

map<pair<int, int>, int> dp;
int getMaxGold(int n, int m, vector<vector<int>> M, pair<int, int> pos) {

    // check if the value already exists in table
    if(dp.find(pos) != dp.end())
        return dp[pos];

    if(pos.second >= m || pos.first < 0 || pos.first >= n)
        return 0;
    
    dp[pos] = M[pos.first][pos.second] + max(getMaxGold(n, m, M, {pos.first - 1, pos.second + 1}), max(getMaxGold(n, m, M, {pos.first, pos.second+1}), getMaxGold(n, m, M, {pos.first+1, pos.second+1})));
    return dp[pos];
}

// Memoization
int maxGold(int n, int m, vector<vector<int>> M) {
    int mx = INT_MIN;
    pair<int, int> pos;
    for(int i=0; i<n; i++) {
        mx = max(mx, getMaxGold(n, m, M, {i, 0}));
    }
    return mx;
}

// Tabulation
int maxGoldTab(int n, int m, vector<vector<int>> M) {
    vector<vector<int>> dp(n+2, vector<int>(m+1, 0));
    for(int i=0; i<n; i++) {
        for(int j=m-1; j>=0; j--) {
            dp[i+1][j] = M[i][j] + max(dp[i][j+1], max(dp[i+1][j+1], dp[i+2][j+1]));
        } 
    }
    int mx = INT_MIN;
    for(int i=0; i<n; i++) {
        mx = max(mx, dp[i+1][0]);
    }
    return mx;
}

int main() {
    vector<vector<int>> gold { 
        {1, 3, 1, 5},
        {2, 2, 4, 1},
        {5, 0, 2, 3},
        {0, 6, 1, 2}
    };
    int n = 4, m = 4;
    cout << maxGoldTab(n, m, gold) << endl;
    return 0;
}