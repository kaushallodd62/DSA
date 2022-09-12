#include<bits/stdc++.h>
#include "declaration.h"
using namespace std;

vector<int> topView (Node *root) {
    if (root == __null)
        return {};

    vector<int> res;
    queue<pair<Node*, int>> q;
    pair<Node *, int> currPair;
    int minOffset = 0, maxOffset = 0;
    res.push_back(root->data);
    q.push({root, 0});
    
    while (!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; i++) {
            currPair = q.front();
            q.pop();

            if (currPair.second < minOffset) {
                minOffset = currPair.second;
                res.insert(res.begin(), currPair.first->data);
            }

            if (currPair.second > maxOffset) {
                maxOffset = currPair.second;
                res.push_back(currPair.first->data);
            }

            if (currPair.first->left)
                q.push({currPair.first->left, currPair.second - 1});

            if (currPair.first->right)
                q.push({currPair.first->right, currPair.second + 1});
        }
    }

    return res;
}