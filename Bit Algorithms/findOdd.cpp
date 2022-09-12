#include<bits/stdc++.h>
using namespace std;

// Given a set of numbers where all elements occur an even number of times except one number, find the odd occurring number
int findOdd(int arr[], int n) {
    int res = 0;
    for(int i=0; i<n; i++) {
        res ^= arr[i];
        cout << res << " ";
    }
    cout << endl;
    return res;
}

int main() {
    int arr[] = { 12, 12, 14, 90, 14, 14, 14 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "The odd occurring element is  "<< findOdd(arr, n) << endl;
    return 0;
}