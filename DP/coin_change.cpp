#include<bits/stdc++.h>
using namespace std;

// recursive solution
long long int count(int S[], int m, int n) {
    if (n == 0)
        return 1;

    if (n < 0)
        return 0;

    if (m <= 0)
        return 0;

    return count(S, m, n-S[m-1]) + count(S, m-1, n);
}

// tabulation method
long long int count (int S[], int m, int n) {
    vector<vector<int>> dp (n+1, vector<int> (m+1, -1));

    // when n = 0, we have made the change successfully
    for(int i = 0; i < m; i++) {
        dp[0][i] =  1;
    }

    // tabulation
    for (int i = 1; i < n+1; i++) {
        for (int j = 0; j < m; j++) {
            if (i - S[j-1] >= 0)
                dp[i][j] = dp[i][j-1] + dp[i - S[j-1]][j];
            else 
                dp[i][j] = dp[i][j-1];
        }
    }

    return dp[n][m];
}