#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int left_child (int i) {
    return (i<<1) + 1;
}

int right_child (int i) {
    return (i<<1) + 2;
}

int parent (int i) {
    return (i-1) >> 1;
}

void min_heapify (vector<int>& arr,  int size, int index) {
    int l, r, smallest;
    l = left_child(index);
    r = right_child(index);
    smallest = index;
    if (l < size && arr[l] < arr[smallest])
        smallest = l;
    if (r < size && arr[r] < arr[smallest])
        smallest = r;
    if (smallest != index) {
        swap(arr[index], arr[smallest]);
        min_heapify(arr, size, smallest);
    }
}

void build_min_heap (vector<int>& arr) {
    int n = parent(arr.size()-1);
    for (int i = n; i >= 0; i--) {
        min_heapify(arr, arr.size(), i);
    }
}

void heapsort (vector<int>& arr) {
    build_min_heap(arr);
    for (int i = arr.size()-1; i > 0; i--) {
        swap(arr[0], arr[i]);
        min_heapify(arr, i, 0);
    }
}

void printArray(vector<int>& arr) {
    for(vector<int> :: iterator it = arr.begin(); it != arr.end(); it++)
        cout << *it << " ";
    cout << "\n";
}

/*int main() {
    int A[] = {5, 3, 17, 10, 84, 19, 6, 22, 9};
    int n = 9;
    vector<int> arr(A, A+n);
    printArray(arr);
    //build_min_heap(arr);
    heapsort(arr);
    printArray(arr);
    return 0;
}*/