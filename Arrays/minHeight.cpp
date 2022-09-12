#include<bits/stdc++.h>
using namespace std;

int getMinDiff(int arr[], int n, int k) {
    sort(arr, arr+n);
    int smallest = arr[0];
    int largest = arr[n-1];
    int ans = largest-smallest;
    for(int i=1; i<n; i++) {
        if(arr[i] < k)
            continue;
        smallest = min(arr[0]+k, arr[i]-k);
        largest = max(arr[n-1]-k, arr[i-1]+k);
        ans = min(ans, largest-smallest);
    }
    return ans;
}