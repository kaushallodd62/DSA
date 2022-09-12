#include<bits/stdc++.h>
using namespace std;

bool isPowerofTwo(long long n) {
    return n && !(n & n-1);
}

// or you can also check the number of set bits and see if it is 1 only.