#include<bits/stdc++.h>
#include "declaration.h"
using namespace std;

// BFS Approach (iterative solution)
bool continousTree(Node* root) {
    if(root == NULL)
        return true;

    if(!root->left && !root->right)
        return true;
    
    queue<Node*> q;
    q.push(root);

    Node* curr;
    while(!q.empty()) {
        curr = q.front();
        q.pop();

        if(curr->left) {
            if(abs(curr->left->data - curr->data) != 1)
                return false;
            q.push(curr->left);
        }
        if(curr->right) {
            if(abs(curr->right->data - curr->data) != 1)
                return false;
            q.push(curr->right);
        }
    }

    return true;
}

// DFS Approach (recursive solution)
bool continousTreeRec(Node* root) {
    if(!root)
        return true;
    
    if(!root->left && !root->right)
        return true;

    if(root->left) {
        if(abs(root->data - root->left->data) != 1)
            return false;
        return continousTreeRec(root->left);
    }

    if(root->right) {
        if(abs(root->data - root->right->data) != 1)
            return false;
        return continousTreeRec(root->right);
    }
}


int main() {
    Node* root = new Node(3);
    root->left = new Node(2);
    root->right = new Node(4);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->right = new Node(5);

    cout << continousTree(root) << endl;
    return 0;
}