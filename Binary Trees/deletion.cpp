#include<bits/stdc++.h>
#include "insertion.cpp"
using namespace std;

Node* deleteNode(Node* root, int key) {
    if(root != NULL) {
        if(!root->left && !root->right) {
            if(root->data == key)
                return NULL;
            else
                return root;
        }
        else {
            queue<Node*> q;
            q.push(root);

            Node *curr, *key_node, *last;
            while(!q.empty()) {
                curr = q.front();
                q.pop();

                if(curr->data == key) {
                    key_node = curr;
                }

                if(curr->left) {
                    last = curr;
                    q.push(curr->left);
                }

                if(curr->right) {
                    last = curr;
                    q.push(curr->right);
                }
            }

            if(key_node) {
                key_node->data = curr->data;
                if(last->right == curr)
                    last->right = NULL;
                else
                    last->left = NULL;
                delete curr;
            }

            return root;
        }
    }
}