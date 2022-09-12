#include<bits/stdc++.h>
using namespace std;

vector<int> singleNumber(vector<int>& arr) {
    int res = 0;
    for(int i=0; i<arr.size(); i++) {
        res ^= arr[i];
    }
    int lsb = res & -res;
    int xxor = 0, yxor = 0;
    for(int i=0; i<arr.size(); i++) {
        if(arr[i] & lsb)
            xxor ^= arr[i];
        else
            yxor ^= arr[i];
    }
    if(xxor > yxor)
        return {yxor, xxor};
    return {xxor, yxor};
}