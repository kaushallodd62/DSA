#include<bits/stdc++.h>
using namespace std;

// here l is closer to lsb and r is closer to msb
// method 1
void copySetBits(int& x, int y, int l, int r) {
    if(l < 1 || r > 32)
        return;
    for(int i=l; i<=r; i++) {
        int mask = 1 << i-1;
        if(y&mask)
            x |= mask;
    }
}

// method 2 (only one mask)
void copySetBits(int& x, int y, int l, int r) {
    if(l < 1 || r > 32)
        return;
    int mask = (((1ll << r-l+1) - 1) << l-1) & y;
    x |= mask;
}