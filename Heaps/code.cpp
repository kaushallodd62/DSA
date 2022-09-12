#include<bits/stdc++.h>
using namespace std;

int getLeftChild(int pi) {
    return (pi<<1)+1;
}

int getRightChild(int pi) {
    return (pi<<1)+2;
}

int getParent(int ci) {
    return (ci-1)>>1;
}

void printHeap(const vector<int>& arr) {
    for(auto& x: arr) {
        cout << x << " ";
    }
    cout << endl;
}

void Heapify(vector<int>& arr, int n, int pi) {
    int li, ri;
    li = getLeftChild(pi);
    ri = getRightChild(pi);

    int mxi = pi;
    if(li < n && arr[li] > arr[mxi])
        mxi = li;
    if(ri < n && arr[ri] > arr[mxi])
        mxi = ri;
    if(mxi != pi) {
        swap(arr[pi], arr[mxi]);
        Heapify(arr, n, mxi);
    }
}

void buildHeap(vector<int>& arr) {
    int last_parent = getParent(arr.size()-1);
    for(int i=last_parent; i>=0; i--) {
        Heapify(arr, arr.size(), i);
    }
}

void heapSort(vector<int>& arr) {
    buildHeap(arr);
    int n = arr.size();
    while(n>0) {
        swap(arr[0], arr[n-1]);
        Heapify(arr, n-1, 0);
        n--;
    }
}

int main() {
    int array[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(array)/sizeof(int);

    vector<int> arr(array, array+n);
    heapSort(arr);

    printHeap(arr);
}