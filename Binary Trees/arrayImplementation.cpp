#include<bits/stdc++.h>
using namespace std;

class BinTree {
    private:
        vector<int> tree;
    public:
        BinTree() {
            // default size set to 10
            tree.resize(10, INT_MIN);
        }
        BinTree(int sz) {
            // constructor with size of tree sz
            tree.resize(sz, INT_MIN);
        }
        
        BinTree& setRoot(int val) {
            tree[0] = val;
            return *this;
        }
        
        vector<int> getTreeArray() {
            return tree;
        }

        BinTree& setLeft(int val, int pi) {
            if(pi>=0 && pi<tree.size() && tree[pi] != INT_MIN) {
                int ci = pi<<1 + 1;
                if(ci<tree.size()) {
                    tree[ci] = val;
                    return *this;
                }
                cout << "Tree Overflow!" << endl;
            }
            cout << "Parent node incorrect or doesn't exist!" << endl;
        }

        BinTree& setRight(int val, int pi) {
            if(pi>=0 && pi<tree.size() && tree[pi] != INT_MIN) {
                int ci = pi<<1 + 2;
                if(ci<tree.size()) {
                    tree[ci] = val;
                    return *this;
                }
                cout << "Tree Overflow!" << endl;
            }
            cout << "Parent node incorrect or doesn't exist!" << endl;
        }

        void printTree() {
            for(auto& node: tree) {
                cout << node << " ";
            }
            cout << endl;
        }

};