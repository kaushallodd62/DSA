#include<bits/stdc++.h>
using namespace std;

// // Brute Force Method (O(n^2))
// long long maxSubarraySum(int arr[], int n) {
//     int left, right;
//     int maxSum = INT_MIN;
//     for(int i=0; i<n; i++) {
//         left = i;
//         int currSum = 0;
//         for(int j=i; j<n; j++) {
//             currSum += arr[j];
//             if(currSum > maxSum) {
//                 maxSum = currSum;
//                 right = j;
//             }
//         }
//     }
//     // cout << left << " " << right << endl;
//     return maxSum;
// }


// // Divide and Conquer Method (O(nlogn))
// long long sumBetweenInterval(vector<int> arr, int low, int mid, int high) {
//     int maxLeftSum = INT_MIN, maxRightSum = INT_MIN;
//     int leftSum = 0, rightSum = 0;
//     for(int i =  mid; i >= low; i--) {
//         leftSum += arr[i];
//         if(leftSum > maxLeftSum) {
//             maxLeftSum = leftSum;
//         }
//     }
//     for(int i = mid+1; i <= high; i++) {
//         rightSum += arr[i];
//         if(rightSum > maxRightSum) {
//             maxRightSum = rightSum;
//         }
//     }
//     return maxLeftSum + maxRightSum;
// }

// long long maxSubarraySumAux(vector<int> arr, int low, int high) {
//     if(low >= high)
//         return arr[low];
    
//     int mid = (low+high)/2;
//     int leftSum = maxSubarraySumAux(arr, low, mid);
//     int rightSum = maxSubarraySumAux(arr, mid+1, high);
//     int intervalSum = sumBetweenInterval(arr, low, mid, high);

//     return max(leftSum, max(rightSum, intervalSum));
// }


// Kadane's Algorithm
long long maxSubarraySum(int arr[], int n) {
    int left = 0, right = 0, start = 0;
    int maxSum = INT_MIN, currSum = 0;
    for(int i=0; i<n; i++) {
        currSum += arr[i];
        if(currSum > maxSum) {
            left = start;
            right = i;
            maxSum = currSum;
        }
        if(currSum < 0) {
            start = i+1;
            currSum = 0;
        }
    }
    return maxSum;
}