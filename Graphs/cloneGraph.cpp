#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        int val;
        vector<Node*> neighbors;

        Node () {
            val = 0;
            neighbors = vector<Node*> ();
        }
        Node (int _val) {
            val = _val;
            neighbors = vector<Node*> ();
        }
        Node (int _val, vector<Node*> _neighbors) {
            val = _val;
            neighbors = _neighbors;
        }
};

// BFS
Node * cloneGraph (Node *node) {
    if (node == __null)
        return __null;
    queue <Node *> q;
    map <Node *, Node *> mp;
    Node *clone = new Node (node->val);

    mp[node] = clone;
    q.push (node);

    while (!q.empty()) {
        Node *curr = q.front();
        q.pop();
        Node *currClone = mp[curr];

        for (auto it = curr->neighbors.begin(); it < curr->neighbors.end(); it++) {
            if (mp.find (*it) == mp.end ()) {
                q.push (*it);
                Node *newClone = new Node ((*it)->val);
                mp[*it] = newClone;
                currClone->neighbors.push_back(newClone);
            }
            else {
                currClone->neighbors.push_back(mp[*it]);
            }
        }
    }
    return clone;
}
