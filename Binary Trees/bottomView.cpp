#include<bits/stdc++.h>
#include"declaration.h"
using namespace std;

vector <int> bottomView (Node *root) {
    if (root == __null)
        return {};

    vector<int> res;
    map<int, Node*> mp;
    queue<pair<Node *, int>> q;
    pair<Node *, int> currPair;
    q.push({root, 0});

    while (!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; i++) {
            currPair = q.front();
            q.pop();
            
            mp[currPair.second] = currPair.first;
            
            if (currPair.first->left)
                q.push ({currPair.first->left, currPair.second - 1});
            
            if (currPair.first->right)
                q.push ({currPair.first->right, currPair.second + 1});
        }
    }

    for (auto x: mp) {
        res.push_back(x.second->data);
    }

    return res;
}