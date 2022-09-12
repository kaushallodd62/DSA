#include<bits/stdc++.h>
#include "declaration.h"
using namespace std;

Node* createNode(int val) {
    Node* node = new Node();
    if(node == NULL) {
        cout << "Memory Full!" << endl;
    }
    else {
        node->data = val;
        node->left = node->right = NULL;
    }
    return node;
}

Node* insertNode(Node* root, int val) {
    Node* newNode = createNode(val);
    if(newNode != NULL) {
        if(root == NULL) {
            root = newNode;
            return root;
        }
        else {
            queue<Node*> q;
            Node* curr = root;
            q.push(curr);
            while(!q.empty()) {
                curr = q.front();
                q.pop();
                if(!curr->left) {
                    curr->left = newNode;
                    return root;
                }
                else {
                    q.push(curr->left);
                }
                if(!curr->right) {
                    curr->right = newNode;
                    return root;
                }
                else {
                    q.push(curr->right);
                }
            }
        }
    }
    return NULL;
}

void inorderTraversal(Node* root) {
    if(root != NULL) {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

int main() {
    Node* root = new Node();
    root = NULL;
    root = insertNode(root, 1);
    root = insertNode(root, 2);
    root = insertNode(root, 3);
    root = insertNode(root, 4);
    root = insertNode(root, 5);
    inorderTraversal(root);
    cout << endl;
    return 0;
}