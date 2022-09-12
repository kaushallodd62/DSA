#ifndef DECLARATION_H
#define DECLARATION_H

// Dynamic Linked Node Representation
class Node {
    public:
        int data;
        Node* left;
        Node* right;

        Node() {
            this->left = this->right = __null;
        }

        Node(int val) {
            this->data = val;
            this->left = this->right = __null;
        }
};

// Sequential Array Representation
// if father = p, then left-child = 2*p+1, and right-child = 2*p+2 using 0-(n-1) 
// if father = p, then left-child = 2*p, and right-child = 2*p+1 using 1-n

#endif