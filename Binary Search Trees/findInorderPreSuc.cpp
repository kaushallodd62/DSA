#include<bits/stdc++.h>
#include "declaration.h"
using namespace std;

void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    if(root == NULL)
        return;
    
    if(root->data > key) {
        suc = root;
        findPreSuc(root->left, pre, suc, key);
    }
    else if(root->data < key) {
        pre = root;
        findPreSuc(root->right, pre, suc, key);
    }
    else {
        Node* curr;
        if(root->left) {
            // predecessor
            curr = root;
            curr = curr->left;
            while(curr->right) {
                curr = curr->right;
            }
            pre = curr;
        }
        if(root->right) {
            // successor
            curr = root;
            curr = curr->right;
            while(curr->left) {
                curr = curr->left;
            }
            suc = curr;
        }
    }
    return;
}