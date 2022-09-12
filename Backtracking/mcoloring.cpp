#include<bits/stdc++.h>
using namespace std;

bool helper(bool graph[101][101], int m, int n, unordered_set<int>& visit, unordered_map<int, int>& colored, int curr, int color) {
    visit.insert(curr);
    colored[curr] = color;
    for(int i=0; i<n; i++) {
        if(graph[curr][i] && )
    }
}

bool graphColoring(bool graph[101][101], int m, int n) {
    unordered_set<int> visit;
    unordered_map<int, int> colored;
}