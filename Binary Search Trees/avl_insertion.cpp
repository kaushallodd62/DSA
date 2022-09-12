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
    if(root == __null) return 0;
    return root->height;
}

int getBalance(Node* root) {
    if(root == __null)
        return 0;
    return height(root->right) - height(root->left);
}

Node* leftRotate(Node* root) {
    Node* new_root = root->right;
    Node* temp = new_root->left;
    new_root->left = root;
    root->right = temp;

    //update heights
    root->height = 1 + max(height(root->left), height(root->right));
    new_root->height = 1 + max(height(new_root->left), height(new_root->right));

    return new_root;
}

Node* rightRotate(Node* root) {
    Node* new_root = root->left;
    Node* temp = new_root->right;
    new_root->right = root;
    root->left = temp;

    //update heights
    root->height = 1 + max(height(root->left), height(root->right));
    new_root->height = 1 + max(height(new_root->left), height(new_root->right));

    return new_root;
}

Node* insert_node(Node* root, int val) {
    if(root == NULL) {
        Node* root = new Node(val);
        return root;
    }
    if(val < root->data) {
        root->left = insert_node(root->left, val);
    }
    else if(val > root->data) {
        root->right = insert_node(root->right, val);
    }
    else return root;

    // increase the height of the node
    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    // left left case
    if(balance < -1 && val < root->left->data)
        return rightRotate(root);
    // left right case
    if(balance < -1 && val > root->left->data) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // right right case
    if(balance > 1 && val > root->right->data)
        return leftRotate(root);

    // right left case
    if(balance > 1 && val < root->right->data) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void preOrder(Node *root)
{
    if(root != NULL)
    {
        preOrder(root->left);
        cout << root->data << " ";
        preOrder(root->right);
    }
}

int main() {
    Node *root = NULL;
     
    /* Constructing tree given in
    the above figure */
    root = insert_node(root, 850);
    root = insert_node(root, 859);
    root = insert_node(root, 912);
    root = insert_node(root, 50);
    root = insert_node(root, 218);
    root = insert_node(root, 545);
    root = insert_node(root, 815);
    root = insert_node(root, 22);
    root = insert_node(root, 903);
     
    /* The constructed AVL Tree would be
                30
            / \
            20 40
            / \ \
        10 25 50
    */
    cout << "Preorder traversal of the "
            "constructed AVL tree is \n";
    preOrder(root);
     
    return 0;
}

// 850 859 912 50 218 545 815 22 903