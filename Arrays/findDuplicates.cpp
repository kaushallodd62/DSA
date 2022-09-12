#include<bits/stdc++.h>
using namespace std;

// using the array as a hash
int findDuplicate(vector<int> arr) {
    for(int i=0; i<arr.size(); i++) {
        int index = abs(arr[i]);
        if(arr[index] < 0)
            return index;
        arr[index] = -arr[index];
    }
    return -1;
}

// Floyd's cycle detection algorithm for finding starting point of loop
int findDuplicate(vector<int> arr) {
    int slow = arr[0], fast = arr[0];
    do {
        slow = arr[slow];
        fast = arr[arr[fast]];
    } while (slow != fast);
    slow = arr[0];
    while(slow != fast) {
        slow = arr[slow];
        fast = arr[fast];
    }
    return slow; // or fast
}

int findDuplicate(vector<int>& arr) {
    bitset<100000> arr(0);
    int ans;
    for(int i=0; i<arr.size(); i++) {
        if(arr[arr[i]]) {
            ans = arr[i];
            break;
        }
        arr[arr[i]] = 1;
    }
    return ans;
}
