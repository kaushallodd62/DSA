#include<bits/stdc++.h>
using namespace std;

#define INF 1000000000
void shortest_distance (vector<vector<int>>& g) {
    int V = g.size();
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (g[i][k] != INF && g[k][j] != INF && g[i][j] > g[i][k] + g[k][j])
                    g[i][j] = g[i][k] + g[k][j];
            }
        }
    }
}