#include<bits/stdc++.h>
using namespace std;

int countBitsFlip(int a, int b) {
    int res = a^b;
    int count = 0;
    while(res) {
        res &= res-1;
        count++;
    }
    return count;
}