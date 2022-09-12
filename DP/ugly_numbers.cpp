#include<bits/stdc++.h>
using namespace std;

// Bottom Up Tabulation
int uglyNumber(int n) {
    vector<int> ugly;
    ugly.push_back(1);
    int i2, i3, i5;
    i2 = i3 = i5 = 0;
    int mult_2 = 2, mult_3 = 3, mult_5 = 5;
    int next_ugly_number;
    for(int i=1; i<n; i++) {
        next_ugly_number = min(mult_2, min(mult_3, mult_5));
        ugly.push_back(next_ugly_number);
        if(next_ugly_number == mult_2) {
            i2++;
            mult_2 = ugly[i2] * 2;
        }
        if(next_ugly_number == mult_3) {
            i3++;
            mult_3 = ugly[i3] * 3;
        }
        if(next_ugly_number == mult_5) {
            i5++;
            mult_5 = ugly[i5] * 5;
        }
    }
    return ugly[n-1];
}

// Bottom Up using Sets
int uglyNumberSet(int n) {
    if(n<=5)
        return n;
    set<int> s;
    s.insert(1);
    n--;
    while(n--) {
        int curr = *s.begin();
        s.erase(s.begin());
        s.insert(curr*2);
        s.insert(curr*3);
        s.insert(curr*5);
    }
    return *s.begin();
}

int main() {
    int n;
    cin >> n;
    cout << uglyNumber(n) << endl;
    return 0;
}