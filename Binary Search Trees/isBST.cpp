#include<bits/stdc++.h>
#include "declaration.h"
using namespace std;

bool isBST(Node* root) {
    vector<int> arr;
    stack<Node*> s;
    Node* curr = root;
    while(!s.empty() || curr != NULL) {
        if(curr) {
            s.push(curr);
            curr = curr->left;
        }
        else {
            curr = s.top();
            s.pop(); 
            arr.push_back(curr->data);
            curr = curr->right;
        }
    }
    int i=0;
    while(i<arr.size()-1 && arr[i] <= arr[i+1])
        i++;
    if(i+1 == arr.size())
        return true;
    else return false;
}