#include<bits/stdc++.h>
using namespace std;

unordered_set<int> visited;
bool isCycleUtil(int V, vector<int> adj[], int node, int parent) {
    visited.insert(node);
    for(int i=0; i<adj[node].size(); i++) {
        if(visited.find(adj[node][i]) == visited.end()) {
            if(isCycleUtil(V, adj, adj[node][i], node))
                return true;
        }
        else if(adj[node][i] != parent)
            return true;
    }
    return false;
}

bool isCycle(int V, vector<int> adj[]) {
    for(int i=0; i<V; i++)
        // initializing parent to -1 first because if we initialized as i and there is only one node, then it will return false for cycle which is wrong.
        if(visited.find(i) == visited.end() && isCycleUtil(V, adj, i, -1))
            return true;
    return false;
}