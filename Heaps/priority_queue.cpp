#include<bits/stdc++.h>
#include"min_heap.cpp"
using namespace std;

int heap_minimum (vector<int>& arr) {
    return arr[0];
}

int heap_extract_minimum (vector<int>& arr) {
    if(arr.size() < 1) {
        cout << "Heap Underflow" << endl;
        exit(1);
    }
    int min = arr[0];
    arr[0] = arr[arr.size()-1];
    arr.pop_back();
    min_heapify(arr, arr.size(), 0);
    return min;
}

void heap_decrease_key (vector<int>& arr, int index, int new_key) {
    if (new_key > arr[index]) {
        cout << "New key is greater than the current key" << endl;
        exit(1);
    }
    while (index >= 0 && new_key < arr[parent(index)]) {
        arr[index] = arr[parent(index)];
        index = parent(index);
    }
    arr[index] = new_key;
}

void min_heap_insert(vector<int>& arr, int key) {
    arr.push_back(INT_MAX);
    heap_decrease_key(arr, arr.size()-1, key);;
}

void heap_delete(vector<int>& arr, int index) {
    heap_decrease_key(arr, index, INT_MIN);
    heap_extract_minimum(arr);
}

int main(int argc, char const *argv[]) {
    int A[] = {15, 13, 9, 5, 12, 8, 7, 4, 0, 6, 2, 1};
    int n = sizeof(A)/sizeof(int);
    vector<int> arr(A, A+n);
    printArray(arr);
    build_min_heap(arr);
    printArray(arr);
    min_heap_insert(arr, 3);
    printArray(arr);
    heap_delete(arr, 5);
    printArray(arr);
    return 0;
}
