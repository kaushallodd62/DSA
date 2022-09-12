#include<bits/stdc++.h>
using namespace std;

class minHeapNode {
    public:
        char data;
        unsigned int freq;
        minHeapNode *left, *right;

        minHeapNode() {
            this->left = this->right = __null;
        }

        minHeapNode(char c, unsigned int f) {
            this->data = c;
            this->freq = f;
            this->left = this->right = __null;
        }

};

// comparator function for heapifying based on frequency
class compare {
    public:
        bool operator() (minHeapNode* a, minHeapNode* b) {
            return a->freq > b->freq;
        }
};

void preOrderTraversal (minHeapNode* root, vector<string>& res, string code) {
    if (root == __null) {
        return;
    }

    // leaf node case
    if (root->data != '$') {
        res.push_back(code);
    }
    
    // preorder traversal
    preOrderTraversal (root->left, res, code + '0');
    preOrderTraversal (root->right, res, code + '1');
}


vector<string> huffmanCodes (string s, vector<int> frequency, int n) {
    if (n == 0)
        return {};

    priority_queue<minHeapNode*, vector<minHeapNode*>, compare> pq;

    // inerting all the characters with their frequency into the heap
    for (int i = 0; i < n; i++) {
        pq.push(new minHeapNode(s[i], frequency[i]));
    }

    // building the huffman tree
    while (pq.size() != 1) {
        minHeapNode *left, *right, *top;
        left = pq.top(); pq.pop();
        right = pq.top(); pq.pop();

        top = new minHeapNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;

        pq.push(top);
    }

    // printing the codes from the huffman tree
    vector<string> res;
    preOrderTraversal (pq.top(), res, "");
    return res;
}