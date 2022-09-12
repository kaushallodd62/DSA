//Will be using vectors instead of linked lists, can also be done with std :: list or std :: forward_list in the STL
#include<iostream>
#include<list>
#include<map>
using namespace std;

void printGraph(map<int, list<int> >& arr, int n) {
    cout << "\nThe Adjacency List representation of the graph: \n";
    for(int i=0; i<n; i++) {
        cout << "Vertex " << i << " -> ";
        for(auto x : arr[i]) {
            cout << x << " -> ";
        }
        cout << "NULL";
        cout << endl;
    }
}

int main() {
    int v;
    cout << "Enter number of vertices: ";
    cin >> v;
    map<int, list<int> > arr;
    cout << "Enter the number of edges: ";
    int e;
    cin >> e;
    for(int i=0; i<e; i++) {
        int v1, v2;
        cout << "Enter the edges (u, v): ";
        cin >> v1 >> v2;
        arr[v1].push_back(v2);
        arr[v2].push_back(v1);  //For undirected Graphs
    }
    for(auto x : arr) {
        x.second.sort();
    }
    printGraph(arr, v);
    return 0;
}