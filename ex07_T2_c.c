#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    struct node *next;
};
typedef struct node node;

node *top;

void initialize(){
    top = NULL;
}

void push(int value){
    node *tmp = malloc(sizeof(node));
    if(tmp == NULL){
        printf("Memory cannot be allocated.\n");
    } else {
        tmp->data = value;
        tmp->next = top;
        top = tmp;
    }
}

int pop(){
    node *tmp;
    int n;
    
    tmp = top;
    n = tmp->data;
    top = top->next;
    free(tmp);

    return n;
}

void display(node *head){
    if(head == NULL){
        printf("NULL\n");
    } else {
        printf("%d ,", head->data);
        display(head->next);
    }
}

int main(void){
    printf("Pushing some elements to our node.\n");
    push(23);
    push(12);
    push(42);
    display(top);

    printf("Now pop 2 elements.\n");
    pop();
    pop();
    display(top);

    return 0;
}