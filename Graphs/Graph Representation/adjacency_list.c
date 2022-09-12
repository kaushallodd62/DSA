#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

typedef struct node_tag {
    int data;
    struct node_tag* next;
}Node;

void init(Node** arr, int v) {
    for(int i=0; i<v; i++) {
        arr[i] = NULL;
    }
}

void insert_edge(Node** arr, int i, int j) {
    Node* head = arr[i];
    Node* new = (Node*)malloc(sizeof(Node));
    new->next = NULL;
    new->data = j;
    if(head == NULL) {
        head = new;
    }
    else {
        Node* nptr = head;
        while(nptr->next != NULL)
            nptr = nptr->next;
        nptr->next = new;
    }
    arr[i] = head;
}

void Input(Node** arr, int v) {
    printf("Enter the number of edges: ");
    int e;
    scanf("%d", &e);
    for(int i=0; i<e; i++) {
        int x, y;
        printf("Enter an edge(u,v): ");
        scanf("%d %d", &x, &y);
        assert(x >= 0 && x < v);
        assert(y >= 0 && y < v);
        insert_edge(arr, x, y);
    }
}

void printGraph(Node** arr, int v) {
    for(int i=0; i<v; i++) {
        printf("Vertex %d -> ", i);
        Node* nptr = arr[i];
        while(nptr != NULL) {
            printf("%d -> ", nptr->data);
            nptr = nptr->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int v;
    printf("Enter Number of Nodes: ");
    scanf("%d", &v);
    Node** arr = (Node**)malloc(sizeof(Node*) * v);
    init(arr, v);
    Input(arr, v);
    printGraph(arr, v);
    return 0;
}