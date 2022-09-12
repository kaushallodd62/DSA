#include<bits/stdc++.h>
using namespace std;

// recursive solution
int editDistanceRec(string s, string t, int m, int n) {
    if (m == 0)
        return n;
    if (n == 0)
        return m;

    if (s[m] == s[n])
        return editDistanceRec(s, t, m-1, n-1);

    return 1 + min(editDistanceRec(s, t, m, n-1), min(editDistanceRec(s, t, m-1, n), editDistanceRec(s, t, m-1, n-1)));
}

// tabulation method
int editDistanceTab(string s, string t, int m, int n) {
    int dp[m+1][n+1];

    // fill the table
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0)
                dp[i][j] = j;
            else if (j == 0)
                dp[i][j] = i;
            else if (s[i-1] == t[j-1])
                dp[i][j] = dp[i-1][j-1];
            else 
                dp[i][j] = 1 + min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1]));
        }
    }
    return dp[m][n];
}

// space optimized tabulation method
int editDistanceTab(string s, string t, int m, int n) {
    int dp[2][n+1];

    for (int i = 0; i <= n; i++) {
        dp[0][i] = i;
    }

    // fill the table
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (j == 0)
                dp[i%2][j] = i;
            else if (s[i-1] == t[j-1])
                dp[i%2][j] = dp[(i-1)%2][j-1];
            else 
                dp[i%2][j] = 1 + min(dp[i%2][j-1], min(dp[(i-1)%2][j], dp[(i-1)%2][j-1]));
        }
    }
    return dp[m%2][n];
}

// memoization method
int editDistanceMem(string s, string t, int m, int n, vector<vector<int>>& dp) {
    if (m == 0)
        return n;
    if (n == 0)
        return m;
    
    if (dp[m][n] != -1)
        return dp[m][n];
    
    if (s[m-1] == t[n-1])
        dp[m][n] = editDistanceMem(s, t, m-1, n-1, dp);
    else
        dp[m][n] = 1 + min(editDistanceMem(s, t, m-1, n, dp), min(editDistanceMem(s, t, m, n-1, dp), editDistanceMem(s, t, m-1, n-1, dp)));

    return dp[m][n];
}


int editDistance(string s, string t) {
    if (s == t)
        return 0;
    int m = s.length(), n = t.length();
    vector<vector<int>> dp (m+1, vector<int> (n+1, -1));
    return editDistanceMem(s, t, m, n, dp);
}
