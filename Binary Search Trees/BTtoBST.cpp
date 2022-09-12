#include<bits/stdc++.h>
#include "declaration.h"
using namespace std;

void inorder(Node* root, vector<int>& arr) {
    if(root == NULL)
        return;
    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
}

Node *binaryTreeToBST (Node *root)
{
    vector<int> arr;
    inorder(root, arr);
    sort(arr.begin(), arr.end());
    stack<Node*> s;
    Node* curr = root;
    int i=0;
    while(!s.empty() || curr) {
        if(curr) {
            s.push(curr);
            curr = curr->left;
        }
        else {
            curr = s.top();
            s.pop();
            curr->data = arr[i];
            i++;
            curr = curr->right;
        }
    }
    return root;
}