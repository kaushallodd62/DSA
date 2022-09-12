#include<bits/stdc++.h>
using namespace std;

// Floyd Warshall Algorthm O(V^3)
// Traverse through each node k, and check for all pairs (i, j) if i can reach j through k. As k increases, the set of intermediate
// nodes become <0, 1, .. k-1>
void transitiveClosureWarshall(vector<vector<int>>& g) {
    int V = g.size();
    // Every element can reach itself
    for(int i=0; i<V; i++)
        g[i][i] = 1;
    for(int k=0; k<V; k++) {
        for(int i=0; i<V; i++) {
            for(int j=0; j<V; j++) {
                g[i][j] = g[i][j] || (g[i][k] && g[k][j]);
            }
        }
    }
    return;
}

void dfs(vector<int> adj[], vector<vector<int>>& tc, int src, int node) {
    if(src == node)
        tc[src][node] = 1;
    
    for(auto it = adj[node].begin(); it < adj[node].end(); it++) {
        if(!tc[src][*it]) {
            tc[src][*it] = 1;
            dfs(adj, tc, src, *it);
        }
    }
}

// DFS Method O(V(V+E)). For dense graph -> O(V^3), for sparse graph -> O(V^2).
vector<vector<int>> transitiveClosureDFS(vector<int> adj[], int V) {
    vector<vector<int>> tc(V, vector<int>(V, 0));
    for(int i=0; i<V; i++) {
        dfs(adj, tc, i, i);
    }
    return tc;
}