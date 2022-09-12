#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int left_child(int i) {
    return (i<<1) + 1;
}

int right_child(int i) {
    return (i<<1) + 2;
}

int parent(int i) {
    return (i-1) >> 1;
}

void max_heapify(vector<int>& arr,  int size, int index) {
    int l, r, largest;
    l = left_child(index);
    r = right_child(index);
    largest = index;
    if (l < size && arr[l] > arr[largest])
        largest = l;
    if (r < size && arr[r] > arr[largest])
        largest = r;
    if (largest != index) {
        swap(arr[index], arr[largest]);
        max_heapify(arr, size, largest);
    }
}

void build_max_heap(vector<int>& arr) {
    int n = parent(arr.size()-1);
    for (int i = n; i >= 0; i--) {
        max_heapify(arr, arr.size(), i);
    }
}

void heapsort(vector<int>& arr) {
    build_max_heap(arr);
    for (int i = arr.size()-1; i > 0; i--) {
        swap(arr[0], arr[i]);
        max_heapify(arr, i, 0);
    }
}

void printArray(vector<int>& arr) {
    for(vector<int> :: iterator it = arr.begin(); it != arr.end(); it++)
        cout << *it << " ";
    cout << "\n";
}

int main() {
    int A[] = {5, 3, 17, 10, 84, 19, 6, 22, 9};
    int n = 9;
    vector<int> arr(A, A+n);
    printArray(arr);
    heapsort(arr);
    printArray(arr);
    return 0;
}