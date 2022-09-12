#include<bits/stdc++.h>
using namespace std;

vector<int> ans;
unordered_set<int> s;

void dfs(int V, vector<int> adj[], int node) {
    s.insert(node);
    ans.push_back(node);
    for(int i=0; i<adj[node].size(); i++) {
        if(s.find(adj[node][i]) == s.end())
            dfs(V, adj, adj[node][i]);
    }
}

vector<int> dfsOfGraph(int V, vector<int> adj[]) {
    // iterating through all the nodes because this solves the problem of unreachability of some nodes in a disconnected graph
    for(int i=0; i<V; i++) {
        if(s.find(i) == s.end())
            dfs(V, adj, i);
    }
    return ans;
}