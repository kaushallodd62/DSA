#include <bits/stdc++.h>
using namespace std;

int carAssemblyRec (vector<vector<int>>& a, vector<vector<int>>& t, vector<int>& e, vector<int>& x, int i, int j, int n) {
    if (j == n-1)
        return a[i][j] + x[i];

    return a[i][j] + min (carAssemblyRec(a, t, e, x, i, j+1, n), t[i][j+1] + carAssemblyRec(a, t, e, x, !i, j+1, n));
}

int carAssemblyMem(vector<vector<int>>& a, vector<vector<int>>& T, vector<int>& e, vector<int>& x, int i, int j, int n, vector<vector<int>> &dp) {
    if (j == n-1)
        return dp[i][j] = a[i][j] + x[i];
    
    if (dp[i][j] != -1)
        return dp[i][j];

    dp[i][j] = a[i][j] + min (carAssemblyMem(a, T, e, x, i, j+1, n, dp), T[i][j+1] + carAssemblyMem(a, T, e, x, !i, j+1, n, dp));
    return dp[i][j];
}

int carAssembly (vector<vector<int>>& a, vector<vector<int>>& T, vector<int>& e, vector<int>& x){
    int n = a[0].size();
    vector<vector<int>> dp (2, vector<int> (n, -1));
    return min (e[0] + carAssemblyMem(a, T, e, x, 0, 0, n, dp), e[1] + carAssemblyMem(a, T, e, x, 1, 0, n, dp));
}

int main () {
    ifstream input;
    ofstream output;
    input.open("fileInput.txt");
    output.open("output.txt");
    int t;
    input >> t;
    while (t--) {
        int n;
        input >> n;
        vector<vector<int>> a (2, vector<int> (n)), b (2, vector<int> (n));
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < n; j++) {
                input >> a[i][j];
            }
        }
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < n; j++) {
                input >> b[i][j];
            }
        }
        vector<int> e(2), x(2);
        for (int i = 0; i < 2; i++) {
            input >> e[i];
        }
        for (int i = 0; i < 2; i++) {
            input >> x[i];
        }
        output << carAssembly(a, b, e, x) << endl;
    }
    input.close();
    output.close();
    return 0;
}