#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define FULL 10

struct node {
    int data;
    struct node *next;
};
typedef struct node node;

struct queue {
    int count;
    struct node *front;
    struct node *rear;
};
typedef struct queue queue;

void initialize(queue *q){
    q->count = 0;
    q->front = NULL;
    q->rear = NULL;
}

bool isEmpty(queue *q){
    return (q->rear == NULL);
}

void enqueue(queue *q, int value){
    if(q->count < FULL){
        node *tmp = malloc(sizeof(node));
        if(tmp == NULL){
            printf("Memory cannot be allocated.\n");
        } else {
            tmp->data = value;
            tmp->next = NULL;
            if(!isEmpty(q)){
                q->rear->next = tmp;
                q->rear = tmp;
            } else {
                q->front = q->rear = tmp;
            }
            q->count++;
        }
    } else {
        printf("List is full.\n");
    }
}

int dequeue(queue *q){
    node *tmp;
    int n = q->front->data;
    tmp = q->front;
    q->front = q->front->next;
    q->count--;
    free(tmp);
    return (n);
}

void display(node *head){
    if(head == NULL){
        printf("NULL\n");
    } else {
        printf("%d, ", head->data);
        display(head->next);
    }
}

int main(void){
    queue *q = malloc(sizeof(queue));
    if(q == NULL){
        printf("Memory cannot be allocated!\n");
    } else {
        initialize(q);
        enqueue(q, 20);
        enqueue(q, 34);
        enqueue(q, 27);
        printf("Queue before dequeue:\n");
        display(q->front);
        dequeue(q);
        printf("Queue after dequeue:\n");
        display(q->front);
    }

    return 0;
}