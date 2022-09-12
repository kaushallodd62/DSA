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

// O(n) time complexity and O(n) auxiliary space
int printKthSmallest(Node* root, int k) {
    vector<int> arr;
    inorder(root, arr);
    return (k <= arr.size() && k > 0)? arr[k-1]: -1;
}

// O(n) time complexity and O(1) auxiliary space
int KthSmallestElement(Node* root, int k) {
    int count = 0;
    stack<Node*> s;
    Node* curr = root;
    while(!s.empty() || curr) {
        if(curr) {
            s.push(curr);
            curr = curr->left;
        }
        else {
            curr = s.top();
            s.pop();
            count++;
            if(count == k)
                return curr->data;
            curr = curr->right;
        }
    }
    return -1;
}
