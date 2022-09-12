#include<bits/stdc++.h>
#include "declaration.cpp"
using namespace std;

bool isFoldableUtil(Node* n1, Node* n2) {
    if(!n1 && !n2)
        return true;
    if(!n1 || !n2)
        return false;
    return isFoldableUtil(n1->left, n2->right) && isFoldableUtil(n1->right, n2->left);
}

bool isFoldable(Node* root) {
    if(root == NULL)
        return true;
    return isFoldableUtil(root->left, root->right);
}
