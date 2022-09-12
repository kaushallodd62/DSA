#include<bits/stdc++.h>
using namespace std;
#define NIL -1
#define MAX 100
int lookup[MAX];
void initialize() {
    lookup[0] = 0;
    lookup[1] = 1;
    for(int i=2; i<MAX; i++) {
        lookup[i] = NIL;
    }
}

// Memoization Method
int fibMem(int n) {
    if(lookup[n] != NIL)
        return lookup[n]; 
    else {
        lookup[n] = fibMem(n-2) + fibMem(n-1);
    }
    return lookup[n];
}

// Tabulation Mehtod
int fibTab(int n) {
    int f[n+1];
    f[0] = 0;
    f[1] = 1;
    for(int i=2; i<=n; i++) {
        f[i] = f[i-1] + f[i-2];
    }
    return f[n];
}

int main() {
    initialize();
    cout << fibMem(40) << endl;
    return 0;
}