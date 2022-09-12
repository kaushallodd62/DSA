#include<bits/stdc++.h>
using namespace std;

void dfs(int& start, vector<int> a, vector<int> b, vector<int> d, int& min_dia) {
    auto it = find(a.begin(), a.end(), start);
    if(it == a.end())
        return;
    int index = it - a.begin();
    start = b[index];
    min_dia = min(min_dia, d[index]);
    dfs(start, a, b, d, min_dia);
}

vector<vector<int>> solve(int n, int p, vector<int> a, vector<int> b, vector<int> d) {
    vector<vector<int>> res;
    unordered_set<int> traverse;
    vector<int> no_incoming;

    // for finding the nodes that have no incoming edges
    for(int i=0; i<p; i++) {
        traverse.insert(b[i]);
    }
    for(int i=1; i<=n; i++) {
        if(traverse.find(i) == traverse.end())
            no_incoming.push_back(i);
    }
    
    for(int i=0; i<no_incoming.size(); i++) {
        int min_dia = INT_MAX;
        int start = no_incoming[i];
        dfs(start, a, b, d, min_dia);
        if(no_incoming[i] != start)
            res.push_back({no_incoming[i], start, min_dia});
    }
    return res;
}
