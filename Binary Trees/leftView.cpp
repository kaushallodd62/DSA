#include<bits/stdc++.h>
#include "declaration.h"
using namespace std;

// print the first element in every level

// VLR Traversal (preorder)
void leftViewAux (Node *root, int level, int& maxLevel, vector<int>& res) {
    if (root == __null)
        return;
    
    if (level > maxLevel) {
        res.push_back(root->data);
        maxLevel = level;
    }

    leftViewAux (root->left, level + 1, maxLevel, res);
    leftViewAux (root->right, level + 1, maxLevel, res);
}

// Recursive solution (O(n))
vector<int> leftView (Node *root) {
    int maxLevel = 0;
    vector<int> res;
    leftViewAux (root, 1, maxLevel, res);
    return res;
}

// Iterative solution (O(n))
vector<int> leftView (Node *root) {
    if (root == __null)
        return {};

    vector<int> res;
    queue<Node *> q;
    Node *curr;
    q.push(root);

    while (!q.empty()) {
        // find the number of nodes in that level
        int sz = q.size();
        for (int i = 0; i < sz; i++) {
            curr = q.front();
            q.pop();

            if (i == 0)
                res.push_back(curr->data);
            
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
    }

    return res;
}

