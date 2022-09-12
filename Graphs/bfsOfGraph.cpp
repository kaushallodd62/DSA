#include<bits/stdc++.h>
using namespace std;

void bfsAux (int n, int node, vector<int>& res, vector<int> adj[], unordered_set<int>& s) {
    queue<int> q;
    q.push (node);
    s.insert (node);
    
    while (!q.empty()) {
        int currNode = q.front();
        q.pop();
        res.push_back(currNode);

        for (int i = 0; i < adj[currNode].size(); i++) {
            if (s.find(adj[currNode][i]) == s.end()) {
                q.push (adj[currNode][i]);
                s.insert (adj[currNode][i]);
            }
        }
    }
}

vector<int> bfsOfGraph (int n, vector<int> adj[]) {
    unordered_set<int> s;
    vector<int> res;
    for (int i = 0; i < n; i++) {
        if (s.find (i) == s.end())
            bfsAux (n, i, res, adj, s);
    }
    return res;
}
