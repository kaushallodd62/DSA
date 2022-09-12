#include<bits/stdc++.h>
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

void min_heapify (vector<vector<int> >& arr,  int size, int index) {
    int l, r, smallest;
    l = left_child(index);
    r = right_child(index);
    smallest = index;
    if (l < size && arr[l][0] < arr[smallest][0])
        smallest = l;
    if (r < size && arr[r][0] < arr[smallest][0])
        smallest = r;
    if (smallest != index) {
        swap(arr[index], arr[smallest]);
        min_heapify(arr, size, smallest);
    }
}

void build_min_heap (vector<vector<int> >& arr) {
    int n = parent(arr.size()-1);
    for (int i = n; i >= 0; i--) {
        min_heapify(arr, arr.size(), i);
    }
}

void merge (vector<int>& ans, vector<vector<int> >& arr) {
    while(arr.size() > 0) {
        ans.push_back(arr[0][0]);
        arr[0].erase(arr[0].begin());
        if(arr[0].size() < 1) {
            arr.erase(arr.begin());
        }
        min_heapify(arr, arr.size(), 0);
    }
}

void printArray(vector<int>& arr) {
    for(vector<int> :: iterator it = arr.begin(); it != arr.end(); it++)
        cout << *it << " ";
    cout << "\n";
}

int main() {
    int k = 3, n = 4;
    vector<vector<int> > arr
    {
        {2, 6, 12, 34},
        {1, 9, 20, 1000},
        {23, 34, 90, 2000}
    };
    build_min_heap(arr);
    vector<int> ans;
    merge(ans, arr);
    printArray(ans);
    return 0;
}

vector<int> mergeKArrays(vector<vector<int>> arr, int K) {
    // pair<int x, pair<int y, int z>> -> x = arr[y][z]
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> ans;
    for(int i=0; i<arr.size(); i++) {
        pq.push({arr[i][0], i});
    }
    pair<int, int> curr;
    while(!pq.empty()) {
        curr = pq.top();
        pq.pop();
        ans.push_back(curr.first);
        if(arr[curr.second].size() > 0) {
            pq.push({arr[curr.second][0], curr.second});
        }
        arr[curr.second].erase(arr[curr.second].begin());
    }
    return ans;
}