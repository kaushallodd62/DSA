#include<bits/stdc++.h>
#include "declaration.h"
using namespace std;

// searching for a node in a BST
Node* search(Node* root, int x) {
    if(root == NULL || root->data == x)
        return root;
    else if(x < root->data)
        return search(root->left, x);
    else
        return search(root->right, x);
}

// inserting a node into a BST recursively
Node* insert(Node* root, int x)  {
    if(root == NULL) {
        root = new Node();
        root->left = root->right = NULL;
        root->data = x;
        return root;
    }
    if(root->data == x)
        cout << "Value already present in BST" << endl;
    else if(x < root->data)
        root->left = insert(root->left, x);
    else
        root->right = insert(root->right, x);
    return root;
}

// inserting a node into a BST iteratively
Node* insertIter(Node* root, int x) {
    if(root == NULL) {
        root = new Node();
        root->left = root->right = NULL;
        root->data = x;
        return root;
    }
    Node* curr = root, *prev = NULL;
    while(curr != NULL) {
        if(x < curr->data) {
            prev = curr;
            curr = curr->left;
        }
        else if(x > curr->data) {
            prev = curr;
            curr = curr->right;
        }
        else {
            cout << "Value already present in BST" << endl;
            return root;
        }
    }
    curr = new Node();
    curr->left = curr->right = NULL;
    curr->data = x;

    if(prev->data < x)
        prev->right = curr;
    else 
        prev->left = curr;
    return root;
}

// deletion operation
Node* deleteNode(Node* root, int x) {
    if(root ==  NULL)
        return NULL;
    
    if(x < root->data)
        root->left = deleteNode(root->left, x);
    else if(x > root->data)
        root->right = deleteNode(root->right, x);
    else {
        // deleting an interior node (by replacing with successor node in in order traversal)
        if(root->left && root->right) {
            Node* curr = root->right;
            while(curr->left)
                curr = curr->left;
            root->data = curr->data;
            root->right = deleteNode(root->right, root->data);
        }

        // deleting a node with only one child
        else if(root->left)  {
            Node* temp = root->left;
            delete(root);
            root = temp;
        }
        else if(root->right) {
            Node* temp = root->right;
            delete(root);
            root = temp;
        }

       // deleing a leaf node
       else {
            delete(root);
            return NULL;
       }
    }
    return root;
}

// recursive in order traversal
void inOrderTraversal(Node* root) {
    if(root ==  NULL)
        return;
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

// iterative in order traversal
void inOrderTraversalIter(Node* root) {
    if(root == NULL)
        return;
    stack<Node*> s;
    Node* curr = root;
    while(!s.empty() || curr != NULL) {
        while(curr) {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        cout << curr->data << " ";
        curr = curr->right;
    }
    cout << endl;
}

// level order traversal
void levelOrderTraversal(Node* root) {
    queue<Node*> q;
    q.push(root);
    Node* curr, *left, *right;
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

int main() {
    Node* root = NULL;
    root = insertIter(root, 50);
    root = insertIter(root, 30);
    root = insertIter(root, 20);
    root = insertIter(root, 40);
    root = insertIter(root, 70);
    root = insertIter(root, 60);
    root = insertIter(root, 80);
 
    cout << "Inorder traversal of the given tree \n";
    inOrderTraversalIter(root);
    cout << "Level order traversal of the given tree \n";
    levelOrderTraversal(root);

    cout << "\nDelete 20\n";
    root = deleteNode(root, 20);
    cout << "Inorder traversal of the modified tree \n";
    inOrderTraversalIter(root);
 
    cout << "\nDelete 30\n";
    root = deleteNode(root, 30);
    cout << "Inorder traversal of the modified tree \n";
    inOrderTraversalIter(root);
 
    cout << "\nDelete 50\n";
    root = deleteNode(root, 50);
    cout << "Inorder traversal of the modified tree \n";
    inOrderTraversalIter(root);
 
    return 0;
}
