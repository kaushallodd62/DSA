#include<bits/stdc++.h>
using namespace std;

// tabulation method 
bool equalPartition (int n, int arr[]) {
    int sum = accumulate(arr, arr+n, 0);
    bool dp[2][sum+1];

    // filling the table
    dp[0][0] = true;
    for (int i = 1; i <= sum; i++) {
        dp[0][i] = false;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= sum; j++) {
            if (j == 0)
                dp[i%2][j] = false;
            else if (j - 2*arr[i-1] >= 0)
                dp[i%2][j] = dp[(i-1)%2][j] || dp[(i-1)%2][j - 2*arr[i-1]];
            else
                dp[i%2][j] = dp[(i-1)%2][j];
        }
    }
    return dp[n%2][sum];
}

// memoized solution
bool equalPartitionsAux (int n, int sum, int arr[], vector<vector<int>>& dp) {
    if (sum < 0)
        return false;
    if (n == 0)
        return dp[n][sum] = (sum == 0);
    
    if (dp[n][sum] != -1) {
        return dp[n][sum];
    }

    dp[n][sum] = equalPartitionsAux(n-1, sum, arr, dp) || equalPartitionsAux(n-1, sum - 2*arr[n-1], arr, dp);
    
    return dp[n][sum];

}

bool equalPartitions (int n, int arr[]) {
    int sum = accumulate(arr, arr+n, 0);
    vector<vector<int>> dp (n+1, vector<int> (sum+1, -1));
    return equalPartitionsAux(n, sum, arr, dp);
}