#include<bits/stdc++.h>
using namespace std;

// // Just sort the array 
// vector<int> shiftAll (vector<int> arr) {
//     sort (arr.begin(), arr.end());
//     return arr;
// }

// Using two pointers
vector<int> shiftAll (vector<int> arr) {
    int left = 0, right = arr.size() - 1;
    while (left < right) {
        if (arr[left] > 0 && arr[right] < 0) {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
        else if (arr[left] > 0 && arr[right] > 0)
            right--;
        else if (arr[left] < 0 && arr[right] < 0)
            left++;
        else {
            left++;
            right--;
        }
    }
    return arr;
}

int main () {
    vector<int> arr = {-12, 11, -13, -5,
               6, -7, 5, -3, 11};
            
    vector<int> res = shiftAll(arr);
    for (auto x: res) {
        cout << x << " ";
    }
    cout << endl;
}