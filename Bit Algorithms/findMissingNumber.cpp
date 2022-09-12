#include<bits/stdc++.h>
using namespace std;

int missingNumber(vector<int>& arr, int n) {
    int res = 0;
    for(int i=1; i<=n; i++) {
        res ^= i;
    }
    for(int i=0; i<n-1; i++) {
        res ^= arr[i];
    }
    return res;
}