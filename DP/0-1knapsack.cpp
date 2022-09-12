#include<bits/stdc++.h>
using namespace std;

// recursive solution
int knapSack (int W, int wt[], int val[], int n) {
    if(n == 0 || W == 0)
        return 0;
    
    if (W - wt[n-1] >= 0)
        return max(knapSack(W, wt, val, n-1), val[n-1] + knapSack(W - wt[n-1], wt, val, n-1));
    else
        return knapSack(W, wt, val, n-1);
}


int knapSackMem (int W, int wt[], int val[], int i, vector<vector<int>>& dp) {
    if (i < 0)
        return 0;
    if (dp[i][W] != -1)
        return dp[i][W];
    
    if (W - wt[i] >= 0)
        dp[i][W] = max(knapSackMem(W, wt, val, i-1, dp), val[i] + knapSackMem(W - wt[i], wt, val, i-1, dp));
    else
        dp[i][W] = knapSackMem(W, wt, val, i-1, dp);
    
    return dp[i][W];
}
 
// DP optimization using memoization
int knapSack (int W, int wt[], int val[], int n) {
    vector<vector<int>> dp (n+1, vector<int> (W+1, -1));
    return knapSackMem(W, wt, val, n-1, dp);
}

// DP optimization using tabulation (O(n*W))
int knapSack (int W, int wt[], int val[], int n) {
    int dp[n+1][W+1];

    // Filling the table
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (j - wt[i-1] >= 0)
                dp[i][j] = max(dp[i-1][j], val[i-1] + dp[i-1][j - wt[i-1]]);
            else 
                dp[i][j] = dp[i-1][j];
        }
    }

    return dp[n][W];
}

// DP optimization using tabulation with optimized space complexity (O(2*W))
int knapSack(int W, int wt[], int val[], int n)
{
    int dp[2][W+1];
    // We know we are always using the current row or
    // the previous row of the array/vector . Thereby we can
    // improve it further by using a 2D array but with only
    // 2 rows i%2 will be giving the index inside the bounds
    // of 2d array dp
 
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            if (i == 0 || j == 0)
                dp[i%2][j] = 0;
            else if (j - wt[i-1] >= 0)
                dp[i%2][j] = max(val[i-1] + dp[(i-1) % 2][j - wt[i-1]], dp[(i-1) % 2][j]);
            else
                dp[i%2][j] = dp[(i-1)%2][j];
        }
    }
    return dp[n%2][W];
}

