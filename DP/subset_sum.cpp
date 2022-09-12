#include<bits/stdc++.h>
using namespace std;

// Recursive Solution
bool isSubsetSum(vector<int> arr, int n, int sum) {
    if(sum == 0)
        return true;
    if(n == 0 || sum < 0)
        return false;
         
    return isSubsetSum(arr, n-1, sum-arr[n-1]) || isSubsetSum(arr, n-1, sum);
}

// Tabulation Method
bool isSubsetSum(vector<int> arr, int sum) {
    int n = arr.size();
    vector<vector<bool>> dp(sum+1, vector<bool>(n+1, false));
    // You can get zero sum from zero size of array (default sum = 0)
    dp[0][0] = true;
    // You can get 0 sum from all sizes of the array (by simply not picking any value)
    for(int i=0; i<=n; i++) {
        dp[0][i] = true;
    }
    // You cannot get any sum by 0 size of array
    for(int i = 1; i <= sum; i++) {
        dp[i][0] = false; 
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= sum; j++) {
            if(arr[i-1] > j)
                dp[j][i] = dp[j][i-1];
            else
                dp[j][i] = dp[j-arr[i-1]][i-1] || dp[j][i-1];
        }
    }
    return dp[sum][n];
}

int main() {

}