#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

typedef struct node_tag {
    int val;
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
    new->val = j;
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
        printf("Enter an edge(u,v):");
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
            printf("%d -> ", nptr->val);
            nptr = nptr->next;
        }
        printf("NULL\n");
    }
}

void DFS(Node** arr, int v, int* visited, int root_vertex) {
    Node* nptr = arr[root_vertex];
    printf("%d ", root_vertex);
    visited[root_vertex] = 1;
    while(nptr != NULL) {
        if(visited[nptr->val] == 0)
            DFS(arr, v, visited, nptr->val);
        nptr = nptr->next;
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
    int* visited = (int*)malloc(sizeof(int) * v);
    memset(visited, 0, sizeof(int)*v);
    printf("DFS Traversal Order: ");
    DFS(arr, v, visited, 0);
    printf("\n");
    return 0;
}