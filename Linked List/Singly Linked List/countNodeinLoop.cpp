#include<bits/stdc++.h>
#include "linkedlist.h"
using namespace std;

// Floyd's cycle detection algorihtm - O(n) and O(1)
int countNodeInLoop(Node* head) {
    Node* fast, *slow;
    slow = fast = head;
    while(slow && fast && fast->next) {
        if(slow == fast) {
            Node* final = slow;
            int count = 1;
            while(slow->next != final) {
                slow = slow->next;
                count++;
            }
            return count;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return 0;
}

// Using unordered_map to store count while traversing the nodes
int countNodesInLoop(Node* head) {
    if(head == __null || head->next == __null)
        return 0;
    unordered_map<Node*, int> mp;
    Node* curr = head;
    int count = 1;
    while(curr != __null) {
        if(mp.find(curr) != mp.end()) {
            return count - mp[curr];
        }
        mp[curr] = count;
        count++;
        curr = curr->next;
    }
    return 0;
}