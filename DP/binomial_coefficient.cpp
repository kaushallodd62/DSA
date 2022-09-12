#include<bits/stdc++.h>
using namespace std;

map<pair<int, int>, int> mp;

// Memoization
int nCrMem(int n, int r) {
    if(n < r)   
        return 0;
    if(mp.find({n, r}) != mp.end())
        return mp[{n, r}];
    if(n == r || r == 0) {
        mp.insert(make_pair(make_pair(n, r), 1));
        return 1;
    }
    mp[{n, r}] = nCrMem(n-1, r) + nCrMem(n-1, r-1);
    return mp[{n, r}];
}

// Tabulation
int nCrTab(int n, int r) {
    if(n < r)
        return 0;
    map<pair<int, int>, int> pr;
    for(int i=0; i<n+1; i++) {
        for(int j=0; j<min(i, r)+1; j++) {
            if(i == j || j == 0)
                pr.insert({{i, j}, 1});
            else
                pr.insert({{i, j}, pr[{i-1, j}] + pr[{i-1, j-1}]});
        }
    }
    return pr[{n, r}];
}

// Tabulation in O(r) Auxilary space (Generates Pascal Triangle)
int nCrTabEff(int n, int r) {
    if(n < r)
        return 0;
    vector<int> arr(n+1, 0);
    arr[0] = 1; // nC0 = 1
    for(int i=1; i<n+1; i++) {
        for(int j=min(i, r); j>0; j--) {
            arr[j] += arr[j-1];
        }
    }
    return arr[r];
}

int nCrFactoring(int n, int r) {
    // base case
    if (r > n)
        return 0;
    // C(n,r) = C(n,n-r)
    if (r > n - r)
        r = n - r;
    int mod = 1000000007;
    // array of elements from n-r+1 to n
    int arr[r];
    for (int i = n - r + 1; i <= n; i++) {
        arr[i - (n-r+1)] = i;
    }
    long int ans = 1;
    // for numbers from 1 to r find arr[j],
    // such that gcd(i,arr[j])>1
    for (int k = 1; k < r + 1; k++) {
        int j = 0, i = k;
        while (j < r) {
            int x = gcd(i, arr[j]);
            if (x > 1) {
                // if gcd>1, divide both by gcd
                arr[j] /= x;
                i /= x;
            }

            // if i becomes 1, no need to search arr
            if (i == 1)
                break;
            j += 1;
        }
    }

    // single pass to multiply the numerator
    for (int i : arr)
        ans = (ans * i) % mod;
    return (int)ans;
}

int main() {
    cout << nCrMem(10, 4) << endl;
    cout << nCrTab(10, 4) << endl;
    cout << nCrTabEff(10, 4) << endl;
    return 0;
}
