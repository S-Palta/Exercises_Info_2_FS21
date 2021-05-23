#include <stdio.h>
#define SIZE 10

// Stack
int stack[SIZE];
int top = -1;

// Queue
int queue[SIZE];
int head = -1;
int tail = -1;
int size = -1;

// Functions for Stack
_Bool isEmptyStack(){
    return top < 0;
}

void push(int value){
    if(top < SIZE -1){
        if(top<0){
            stack[0] = value;
            top = 0;
        } else {
            stack[top+1] = value;
            top++;
        }
    } else {
        printf("Stack overflow!\n");
    }
    
}

int pop(){
    if(!isEmptyStack()){
        int n = stack[top];
        top--;
        return n;
    }
    printf("The stack is empty sir!\n");
    return -9999999;
}

void displayStack(int stack[SIZE]){
    printf("{");
    for(int i = 0; i <= top; ++i)
        printf("%d, ", stack[i]);
    printf("}\n");
}

// Functions for Queue
_Bool isEmptyQueue(){
    return size < 0;
}

_Bool isFullQueue(){
    return size == SIZE;
}

void enqueue(int value){
    if(size < SIZE){
        if(size < 0){
            queue[0] = value;
            head = tail = 0;
            size = 1;
        } else if(tail == SIZE - 1){
            queue[0] = value;
            tail = 0;
            size++;
        } else {
            queue[tail+1] = value;
            tail++;
            size++;
        }
    } else {
       printf("Queue is full.\n");
    }  
}

void dequeue(){
    if(!isEmptyQueue()){
        size--;
        if(head < SIZE -1){
            head = 0;
        } else {
            head++;
        }
    } else {
        printf("The queue is already empty.\n");
    }
}

int Head(){
    return queue[head];
}

void displayQueue(int queue[]){
    printf("{");
    if(tail >= head){
        for(int i = head; i < tail; ++i)
            printf("%d, ", queue[i]);
    } else {
        for(int i = head; i < SIZE; ++i)
            printf("%d, ", queue[i]);
        for(int i = 0; i < tail; ++i)
            printf("%d, ", queue[i]);
    }
    printf("}\n");
}


int main(void){

    // Task a)
    push(90);
    push(20);
    push(12);
    push(42);
    displayStack(stack);
    pop();
    displayStack(stack);

    // Task b)
    enqueue(20);
    enqueue(32);
    enqueue(4892);
    enqueue(9876);
    displayQueue(queue);
    dequeue();
    dequeue();
    displayQueue(queue);


    return 0;
}