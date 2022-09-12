#include<bits/stdc++.h>
using namespace std;

vector<int> minPartition(int N) {
    vector<int> denom = {2000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
    int i = 0;
    vector<int> res;
    while(i < denom.size() && N > 0) {
        if(denom[i] <= N) {
            N -= denom[i];
            res.push_back(denom[i]);
        }
        else i++;
    }
    return res;
}