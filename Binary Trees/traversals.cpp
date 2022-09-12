#include<bits/stdc++.h>
#include "declaration.h"
using namespace std;

// preorder traversal (DFS)
void preOrder (Node* root) {
    if (root) {
        cout << root->data << " ";
        preOrder (root->left);
        preOrder (root->right);
    }
}

// inorder traversal (DFS)
void inOrderRec (Node* root) {
    if (root) {
        inOrderRec (root->left);
        cout << root->data << " ";
        inOrderRec (root->right);
    }
}

// postorder traversal (DFS)
void postOrder (Node* root) {
    if (root) {
        postOrder (root->left);
        postOrder (root->right);
        cout << root->data << " ";
    }
}

// inorder traversal without recursion
void inOrderIter (Node *root) {
    if (root == __null)
        return;

    stack<Node *> s;
    Node *curr = root;
    while (!s.empty() || curr) {
        if (curr) {
            s.push(curr);
            curr = curr->left;
        }
        else {
            curr = s.top();
            s.pop();
            cout << curr->data << " ";
            curr = curr->right;
        }
    }
}

// function to get the height of the tree
int getHeightOfTree (Node *root) {
    if (root == __null)
        return 0;

    int leftHeight = getHeightOfTree (root->left);
    int rightHeight = getHeightOfTree (root->right);

    return 1 + max (leftHeight, rightHeight);
}

// function to print the node in a particular level
void printCurrentLevel (Node *root, int level) {
    if (root == __null)
        return;

    if (level == 1)
        cout << root->data << " ";
    else if (level > 1) {
        printCurrentLevel (root->left, level-1);
        printCurrentLevel (root->right, level-1);
    }
}
 
// level order traversal (BFS) [O(n^2) using recursion]
void levelOrder (Node *root) {
    int h = getHeightOfTree(root);
    for (int i = 1; i <= h; i++) {
        printCurrentLevel (root, i);
    }
}

// level order traversal (BFS) [O(n) using queue]
void levelOrderIter (Node* root) {
    queue<Node*> q;
    q.push(root);

    Node* curr;
    while(!q.empty()) {
        curr = q.front();
        q.pop();
        cout << curr->data << " ";

        if(curr->left) {
            q.push(curr->left);
        }
        if(curr->right) {
            q.push(curr->right);
        }
    }
}

void reverseLevelOrder (Node *root) {
    if (root == __null)
        return;
    
    vector<int> res;
    stack<Node *> s;
    queue<Node *> q;
    Node *curr;

    q.push (root);
    while (!q.empty()) {
        curr = q.front();
        s.push(curr);
        q.pop();

        if (curr->right)
            q.push(curr->right);

        if (curr->left)
            q.push(curr->left);

    while (!s.empty()) {
        curr = s.top();
        cout << curr->data << " ";
        s.pop();
    }
    cout << endl;
}
