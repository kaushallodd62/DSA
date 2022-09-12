#include<bits/stdc++.h>
#include "declaration.h"
using namespace std;

void inOrder (Node *root) {
    if (root == __null)
        return;
    
    inOrder(root->left);
    cout << root->data << " ";
    inOrder (root->right);
}

// create a new tree which is the mirror image of the given tree
Node* mirrorify (Node *root) {
    if (root == __null) {
        return __null;
    }

    Node *mirrorRoot = new Node (root->data);
    mirrorRoot->right = mirrorify (root->left);
    mirrorRoot->left = mirrorify (root->right);

    return mirrorRoot;
}

// changing the existing tree to it's mirror image
void mirrorTree (Node *root) {
    if (root == __null)
        return;

    swap(root->left, root->right);
    mirrorTree (root->left);
    mirrorTree (root->right);
}

int main () {
    Node* tree = new Node(5);
    tree->left = new Node(3);
    tree->right = new Node(6);
    tree->left->left = new Node(2);
    tree->left->right = new Node(4);
    printf("Inorder of original tree: ");
    inOrder(tree);
 
    // Function call
    mirrorTree(tree);
 
    printf("\nInorder of Mirror tree: ");
    inOrder(tree);
    return 0;
}