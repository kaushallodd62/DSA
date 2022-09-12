#include<bits/stdc++.h>
using namespace std;

unordered_set<int> visited, recStack;
bool isCyclicUtil(int V, vector<int> adj[], int node) {
    visited.insert(node);
    recStack.insert(node);

    for(int i=0; i<adj[node].size(); i++) {
        if(visited.find(adj[node][i]) == visited.end() && isCyclicUtil(V, adj, adj[node][i]))
            return true;
        else if(recStack.find(adj[node][i]) != recStack.end())
            return true;
    }

    recStack.erase(node);
    return 0;    
}

bool isCyclic(int V, vector<int> adj[]) {
    for(int i=0; i<V; i++)
        if(visited.find(i) == visited.end() && isCyclicUtil(V, adj, i))
            return true;
    return false;
}