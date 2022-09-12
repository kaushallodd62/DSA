#include<bits/stdc++.h>
using namespace std;

// Basic Recursion Solution
int nPrRec(int n, int r) {
    if(n < r)
        return 0;
    if(r == 0)
        return 1;
    return nPrRec(n-1, r) + r*nPrRec(n-1, r-1);
}

// Tabulation Method
int nPrTab(int n, int r) {
    if(n<r)
        return 0;
    map<pair<int, int>, int> pr;
    for(int i=0; i<=n ; i++) {
        for(int j=0; j<=min(i, r); j++) {
            if(j == 0)
                pr.insert({{i, j}, 1});
            else
                pr.insert({{i, j}, pr[{i-1, j}] + (j*pr[{i-1, j-1}])});
        }
    }
    return pr[{n, r}];
}

int nPrIter(int n, int r) {
    if(n<r)
        return 0;
    int ans = 1;
    for(int i=0; i<r; i++) {
        ans *= (n-i);
    }
    return ans;
}

int main() {
    cout << nPrRec(10, 4) << endl;
    cout << nPrTab(10, 4) << endl;
    cout << nPrIter(10, 4) << endl;
    return 0;
}