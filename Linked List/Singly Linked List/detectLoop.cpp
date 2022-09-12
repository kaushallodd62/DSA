#include<bits/stdc++.h>
#include "linkedlist.h"
using namespace std;

//  Method 1: hashing using sets
bool detectLoop(Node* head) {
    unordered_set<Node*> s;
    while(head != __null) {
        if(s.find(head) != s.end())
            return true;
        s.insert(head);
        head = head->next;
    }
    return false;
}

// Method: we can also solve this by augmenting the linked list structure and storing a visited bool in it.

// Method 3: Floyd's cycle-finding algorithm
bool detectLoopFloyd(Node* head) {
    Node* slow, *fast;
    slow = fast = head;
    while(slow && fast && fast->next) {
        if(slow == fast)
            return true;
        slow = slow->next;
        fast = fast->next->next;
    }
    return false;
}

// Method 4: using a temp node and making every node's next point to that temp;
bool detectLoopTemp(Node* head) {
    Node* temp = new Node();
    while(head != __null) {
        if(head->next == temp)
            return true;
        Node* next = head->next;
        head->next = temp;
        head = next;
    }
    return false;
}

// Method 5: we can also create a function distance() which calculates the distance between head and the current node,
// if the distance is a non-decreasing function, then no loops, else if the new distance < pev distance, there is a loop.
// More complexity O(n^2)