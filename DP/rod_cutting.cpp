#include<bits/stdc++.h>
using namespace std;

int cutRodAux(const vector<int>& price, int n, vector<int>& mem) {
    if(mem[n] >= 0)
        return mem[n];
    else {
        int value = INT_MIN;
        for(int i=0; i<n; i++) {
            value = max(value, price[i] + cutRodAux(price, n-i-1, mem));
        }
        mem[n] = value;
        return mem[n];
    }
}

// Memoization (Top down)
int cutRodTD(const vector<int>& price, int n) {
    vector<int> mem(n+1, INT_MIN);
    mem[0] = 0;
    return cutRodAux(price, n, mem);
}

// Tabulation Method (Bottom Up)
int cutRodBU(const vector<int>& price, int n) {
    vector<int> dp(n+1);
    dp[0] = 0;
    for(int i=1; i<=n; i++) {
        int value = INT_MIN;
        for(int j=0; j<i; j++) {
            value = max(value, price[j] + dp[i-j-1]);
        }
        dp[i] = value;
    }
    return dp[n];
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> price;
        for(int i=0; i<n; i++) {
            int temp;
            cin >> temp;
            price.push_back(temp);
        }
        cout << cutRodTD(price, n) << endl;
    }
    return 0;
}