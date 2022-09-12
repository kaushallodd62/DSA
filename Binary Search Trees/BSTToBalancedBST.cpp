#include<bits/stdc++.h>
#include "declaration.h"
using namespace std;

void levelOrder(Node* root) {
    queue<Node*> q;
    q.push(root);
    Node* curr;
    while(!q.empty()) {
        curr = q.front();
        q.pop();
        cout << curr->data << " ";
        if(curr->left)
            q.push(curr->left);
        if(curr->right)
            q.push(curr->right);
    }
    cout << endl;
}

void inorder(Node* root, vector<Node*>& arr) {
    if(root == NULL)
        return;
    inorder(root->left, arr);
    arr.push_back(root);
    inorder(root->right, arr);
}

Node* buildBalancedTreeAux(Node* root, vector<Node*>& arr, int l, int r) {
    if(l <= r) {
        int mid = (l+r)/2;
        root = arr[mid];
        root->left = buildBalancedTreeAux(root->left, arr, l, mid-1);
        root->right = buildBalancedTreeAux(root->right, arr, mid+1, r);
        return root;
    }
    return NULL;
}

Node* buildBalancedTree(Node* root)
{
    vector<Node*> arr;
    inorder(root, arr);
    root = buildBalancedTreeAux(root, arr, 0, arr.size()-1);
    return root;
}

int main() {
    /* Constructed skewed binary tree is
                10
               /
              8
             /
            7
           /
          6
         /
        5   */
 
    Node* root = new Node();
    root->data = 10;
    root->left = new Node();
    root->left->data = 8;
    root->left->left = new Node();
    root->left->left->data = 7;
    root->left->left->left = new Node();
    root->left->left->left->data = 6;
    root->left->left->left->left = new Node();
    root->left->left->left->left->data = 5;
 
    root = buildBalancedTree(root);

    levelOrder(root);
    return 0;
}