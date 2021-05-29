#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>
#define STACK_SIZE 100

int stack[STACK_SIZE];
int s_top = -1;

void stack_push(int value){
    // if we have space to push
    if(s_top < STACK_SIZE - 1){
        // if nothing in the stack, add the value as the first value
        if(s_top < 0){
            stack[0] = value;
            s_top = 0;
        } else {
            stack[s_top+1] = value;
            s_top++;
        }
    } else {
        printf("Stackoverflow!!!\n");
    }
}

bool stack_isempty(){
    return s_top < 0;
}

int stack_pop(){
    // if the stack is not empty
    if(!stack_isempty()){
        int n = stack[s_top];
        s_top--;
        return n;
    } else {
        printf("Error: the stack is empty!\n");
        return INT_MIN;
    }
}

int stack_top(){
    if(!stack_isempty())
        return stack[s_top];
    else{
        printf("Error: The stack is empty!\n");
        return INT_MIN;
    }
}

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

struct node* createNode(int v){
    struct node* newNode = calloc(1, sizeof(struct node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices){
    struct Graph* graph = calloc(1, sizeof(struct Graph));
    graph->numVertices = vertices;

    graph->adjLists = calloc(vertices, sizeof(struct Graph));

    for(int i = 0; i < vertices; i++)
        graph->adjLists[i] = NULL;
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest){
    // Add edge from src to dest
    struct node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[dest] = newNode;

    // Add edge from dest to src
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

void printGraph(struct Graph* graph){
    for(int v = 0; v < graph->numVertices; v++){
        struct node* temp = graph->adjLists[v];
        printf("\n Adjacency list of vertex %d\n ", v);
        while(temp){
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

void DFS(struct Graph * graph, int start){
    // Create an array of boolean of whether a vertice has been added or not
    bool added[graph->numVertices];
    memset(added, false, sizeof added);

    // first item
    stack_push(start);
    added[start] = true;
    while(!stack_isempty()){
        int current = stack_top();
        stack_pop();
        // mark current node as visited and print it
        printf("Visited %d\n", current);

        struct node* adjList = graph->adjLists[current];
        struct node* temp = adjList;

        // while we still have neighbors
        while(temp != NULL){
            int connectedVertex = temp->vertex;
            if(added[connectedVertex] == 0) { // if they are unvisited, visit them
                stack_push(connectedVertex);
                added[connectedVertex] = true;
            }
            temp = temp->next; // check next neighbor
        }
    }
}


int main(void){
    struct Graph* graph = createGraph(4);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);

    printGraph(graph);

    DFS(graph, 2);

    return 0;
}