#include<bits/stdc++.h>
#include "declaration.h"
using namespace std;

// VRL traversal
void rightViewAux (Node *root, int level, int& maxLevel, vector<int>& res) {
    if (root == __null)
        return;

    if (level > maxLevel) {
        maxLevel = level;
        res.push_back(root->data);
    }
    
    rightViewAux(root->right, level + 1, maxLevel, res);
    rightViewAux(root->left, level + 1, maxLevel, res);
}

vector<int> rightView (Node *root) {
    vector<int> res;
    int maxLevel = 0;
    rightViewAux (root, 1, maxLevel, res);
    return res;
}

// You can also do level order traversal and look for the last element in each level.