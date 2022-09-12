#include<bits/stdc++.h>
#include "declaration.h"
using namespace std;

bool isBalanced(Node* root, int& height) {
    if(root == NULL) {
        height = 0;
        return true;
    }

    int lh = 0, rh = 0;
    bool l, r;
    l = isBalanced(root->left, lh);
    r = isBalanced(root->right, rh);

    height = max(lh, rh) + 1;

    if(abs(lh-rh) > 1)
        return false;
    
    return l && r;
}
