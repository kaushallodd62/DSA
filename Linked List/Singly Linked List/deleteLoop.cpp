#include<bits/stdc++.h>
#include "linkedlist.h"
using namespace std;

void removeLoop(Node* head) {
    unordered_set<Node*> s;
    Node* curr = head, *prev = __null;
    while(curr != __null) {
        if(s.find(curr) != s.end()) {
            prev->next = __null;
            return;
        }
        s.insert(curr);
        prev = curr;
        curr = curr->next;
    }
}