#include<bits/stdc++.h>
#include "linkedlist.h"
using namespace std;

// 1->2->3->4->5->6

// recursive method
Node* reverseList(Node* head) {
    if(head == __null || head->next == __null)
        return head;
    
    Node* rest = reverseList(head->next);
    head->next->next = head;
    head->next = __null;
    return rest;
}

// iterative method
Node* reverseListIter(Node* head) {
    if(head == __null || head->next == __null)
        return head;

    Node* prev = __null, *next = __null, *curr = head;
    while(curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    return head;
}