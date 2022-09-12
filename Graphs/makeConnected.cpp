#include <bits/stdc++.h>
using namespace std;

void dfs (int node, vector<int> adj[], unordered_set<int>& s) {
    s.insert (node);
    for (int i = 0; i < adj[node].size(); i++) {
        int curr = adj[node][i];
        if (s.find(curr) == s.end()) {
            dfs (curr, adj, s);
        }
    }
}

int makeConnected(int n, vector<vector<int>>& connections) {
    if (connections.size() < n - 1)
        return -1;
    
    vector<int> adj[n];
    for (int i = 0; i < connections.size(); i++) {
        adj[connections[i][0]].push_back(connections[i][1]);
        adj[connections[i][1]].push_back(connections[i][0]);
    }
    int conn = 0;
    unordered_set<int> s;
    for (int i = 0; i < n; i++) {
        if (s.find(i) == s.end()) {
            conn++;
            dfs (i, adj, s);
        }
    }
    return conn-1;
}