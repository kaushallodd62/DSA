#include<bits/stdc++.h>
#include "declaration.h"
using namespace std;

// DP optimization
unordered_map<Node *, int> dp;
int height (Node *root) {
    if (root == __null)
        return 0;
    if (dp.find(root) != dp.end())
        return dp[root];
    
    return dp[root] = 1 + max (height (root->left), height (root->right));
}

// Normal height method
int height (Node *root) {
    if (root == __null)
        return 0;
    
    return 1 + max (height(root->left), height(root->right));
}

int diameter (Node *root) {
    if (root == __null)
        return 0;

    int dia = 1 + height (root->left) + height (root->right);
    return max (dia, max (diameter (root->left), diameter (root->right)));
}
