#include <stdio.h>
#include <stdlib.h>
#define MAX 10

void addFront(int *, int, int *, int *);
void addRear(int *, int, int *, int *);
int delFront(int *, int *, int *);
int delRear(int *, int *, int *);
void display(int *);
int count(int *);

int main(void){
    int Arr[MAX];
    int front, rear, n;

    front = rear = -1;
    for(int i = 0; i < MAX; ++i)
        Arr[i] = 0;

    addRear(Arr, 12, &front, &rear);
    addFront(Arr, 322, &front, &rear);
    addRear(Arr, 11, &front, &rear);
    addFront(Arr, 42, &front, &rear);
    addRear(Arr, 666, &front, &rear);
    addFront(Arr, 4224, &front, &rear);

    printf("Elements in queue: ");
    display(Arr);
    int i = delFront(Arr, &front, &rear);
    printf("\nRemoved item from the queue is %d", i);

    printf("\nElements in deque after deletion: ");
    display(Arr);

    addRear(Arr, 1291, &front, &rear);
    addRear(Arr, 2020, &front, &rear);

    printf("\nElements after addition: ");
    display(Arr);

    i = delRear(Arr, &front, &rear);
    printf("\nRemoved item is: %d", i);

    printf("\nElements in deque after deletion: ");
    display(Arr);

    n = count(Arr);
    printf("\nTotal number of elements in deque: %d\n", n);

    return 0;
}

void addFront(int *Arr, int value, int *pFront, int *pRear){
    int i, k, c;

    if(*pFront == 0 && *pRear == MAX -1){
        printf("\nDeque is full mate.\n");
        return;
    }

    if(*pFront == -1){
        *pFront = *pRear = 0;
        Arr[*pFront] = value;
    }

    if(*pRear != MAX -1){
        c = count(Arr);
        k = *pRear + 1;
        for(i = 1; i <= c; ++i){
            Arr[k] = Arr[k-1];
            k--;
        }
        Arr[k] = value;
        *pFront = k;
        (*pRear)--;
    } else {
        (*pFront)--;
        Arr[*pFront] = value;
    }
}

void addRear(int *Arr, int value, int *pFront, int *pRear){
    int i, k;

    if(*pFront == 0 && *pRear == MAX -1){
        printf("\nDeque is full\n");
        return;
    }

    if(*pFront == -1){
        *pRear = *pFront = 0;
        Arr[*pRear] = value;
        return;
    }

    if(*pRear == MAX -1){
        k = *pFront - 1;
        for(i = *pFront -1; i < *pRear; ++i){
            k = i;
            if(k == MAX -1)
                Arr[k] = 0;
            else
                Arr[k] = Arr[i+1];
        }
        (*pRear)--;
        (*pFront)--;
    }
    (*pRear)++;
    Arr[*pRear] = value;
}

int delFront(int *Arr, int *pFront, int *pRear){
    int value;
    if(*pFront == -1){
        printf("\nDeque is empty.\n");
        return 0;
    }

    value = Arr[*pFront];
    Arr[*pFront] = 0;

    if(*pFront == *pRear)
        *pFront = *pRear = -1;
    else
        (*pFront)++;

    return value;
}

int delRear(int *Arr, int *pFront, int *pRear){
    int value;

    if(*pFront == -1){
        printf("\nDeque is empty.\n");
        return 0;
    }

    value = Arr[*pRear];
    Arr[*pRear] = 0;
    (*pRear)--;
    if(*pRear == -1)
        (*pFront) = -1;
    return value;
}

void display(int *Arr){
    int i;

    printf("\nfront: ");
    for(i = 0; i < MAX; ++i)
        printf(" %d", Arr[i]);
    printf("  :rear");
}

int count(int *Arr){
    int c = 0;

    for(int i = 0; i < MAX; ++i){
        if(Arr[i] != 0)
            c++;
    }
    return c;
}