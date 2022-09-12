#include<bits/stdc++.h>
using namespace std;

int partition (vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    
}

void quickSort (vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort (arr, low, pi);
        quickSort (arr, pi, high);
    }
}

int main() {
    vector<int> arr = {10, 80, 30, 90, 40, 50, 70};
    quickSort (arr, 0, arr.size()-1);
    for (int x: arr) {
        cout << x << " " << endl;
    }
    return 0;
}