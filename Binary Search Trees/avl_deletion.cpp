#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data, height;
        Node* left, *right;
        Node() {
            left = right = __null;
            height = 1;
        }
        Node(int val) {
            left = right = __null;
            data = val;
            height = 1;
        }
};

int height(Node* root) {
    if(root == __null)
        return 0;
    return root->height;
}

int getBalance(Node* root) {
    if(root == __null)
        return 0;
    return height(root->right) - height(root->left);
}

Node* leftRotate(Node* root) {
    Node* new_root = root->right;
    root->right = new_root->left;
    new_root->left = root;

    // update heights
    root->height = 1 + max(height(root->left), height(root->right));
    new_root->height = 1 + max(height(new_root->left), height(new_root->right));

    return new_root;
}

Node* rightRotate(Node* root) {
    Node* new_root = root->left;
    root->left = new_root->right;
    new_root->right = root;

    // update heights
    root->height = 1 + max(height(root->left), height(root->right));
    new_root->height = 1 + max(height(new_root->left), height(new_root->right));

    return new_root;
}

Node* deleteNode(Node* root, int data) {
    if(root ==  __null)
        return root;
    
    if(data < root->data)
        root->left = deleteNode(root->left, data);
    else if(data > root->data)
        root->right = deleteNode(root->right, data);
    else {
        if(root->left && root->right) {
            Node* curr = root->right;
            while(curr->left != __null) {
                curr = curr->left;
            }
            root->data = curr->data;
            root->right = deleteNode(root->right, root->data);
        }
        else if(root->left) {
            Node* temp = root->left;
            delete(root);
            root = temp;
        }
        else if(root->right) {
            Node* temp = root->right;
            delete(root);
            root = temp;
        }
        else {
            delete(root);
            return __null;
        }
    }
    // update height of the current node
    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);
    // left left case
    if(balance < -1 && getBalance(root->left) <= 0)
        return rightRotate(root);
    // left right case
    if(balance < -1 && getBalance(root->left) > 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    // right right case
    if(balance > 1 && getBalance(root->right) >= 0)
        return leftRotate(root);
    // right left case
    if(balance > 1 && getBalance(root->right) < 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}