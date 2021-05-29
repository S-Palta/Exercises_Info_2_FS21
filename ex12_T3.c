#include <stdio.h>
#include <stdlib.h>

struct node {
    int vertex;
    struct node* next;
};

struct node* createNode(int v);

struct Graph {
    int numVertices;
    // We need int** to store a two dimensional array.
    // Similarly, we need struct node** to store an array of linked lists
    struct node** adjLists;
};

int main(void){

    return 0;
}