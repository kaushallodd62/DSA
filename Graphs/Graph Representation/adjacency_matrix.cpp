#include<iostream>
using namespace std;

void printGraph(int** arr, int n) {
    cout << "\nThe Matrix representation of the graph: \n";
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int v;
    cout << "Enter number of vertices: ";
    cin >> v;
    int** arr = new int*[v];
    for(int i=0; i<v; i++) {
        arr[i] = new int[v];
    }
    cout << "Enter the number of edges: ";
    int e;
    cin >> e;
    cout << "Enter the edges: (v1, v2)" << endl;
    for(int i=0; i<e; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        arr[v1][v2] = 1;
        arr[v2][v1] = 1; // for undirected graphs
    }
    printGraph(arr, v);
    return 0;
}