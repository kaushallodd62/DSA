#include<bits/stdc++.h>
using namespace std;

// Recursive Solution - exponential time complexity
unsigned long int catalanRec(int n) {
    if(n<=1)
        return 1;

    unsigned long int res = 0;
    for(int i=0; i<n; i++) {
        res += catalanRec(i) * catalanRec(n-i-1);
    }
    return res;
}

// DP solution - O(n^2) complexity
unsigned long int catalanDP(int n) {
    vector<int> dp(n+1, 0);
    dp[0] = dp[1] = 1;

    for(int i=2; i<=n; i++) {
        for(int j=0; j<i; j++) {
            dp[i] += dp[j] * dp[i-j-1];
        }
    }
    return dp[n];
}


unsigned long int nCr(unsigned int n, unsigned int k) {
    if(n-k < k) {
        k = n-k;
    }
    unsigned long int res = 1;
    for(int i=0; i<k; i++) {
        res *= (n-i);
        res /= (i+1);   // use i+1 and not r-i as dividing by i+1 will never give decimal value
    }
    return res;
}

// Binomial Coefficient - O(n)
unsigned long int catalanBC(int n) {
    unsigned long int res = nCr(2*n, n);
    return res/(n+1);
}

int main() {
    int n;
    cin >> n;
    cout << catalanRec(n) << endl;
    cout << catalanDP(n) << endl;
    cout << catalanBC(n) << endl;
    return 0;
}