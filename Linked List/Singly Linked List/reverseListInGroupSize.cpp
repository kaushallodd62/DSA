#include<bits/stdc++.h>
#include "linkedlist.h"
using namespace std;

Node* reverse(Node* head, int k) {
    if(head == __null || head->next == __null)
        return head;
    Node* prev = __null, *next = __null, *curr = head;
    int count = 0;
    while(curr && count < k) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    if(curr != __null) {
        head->next = reverse(curr, k);
    }
    return prev;
}