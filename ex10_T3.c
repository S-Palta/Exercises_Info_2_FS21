#include <stdio.h>
#include <math.h>
#define m 7 

void init(int A[m]){
    for(int i = 0; i < m; ++i)
        A[i] = 0;
}

int h(int k, int i){
    int h1 = (k % m) + 1;
    int h2 = (m-1) - (k % (m-1));
    return (int)(h1 + i * h2) % m;
}

void insert(int A[m], int key){
    int counter = 0;
    int hkey;
    do {
        hkey = h(key, counter);
    } while(A[hkey] != 0 && counter++ < m);
    A[hkey] = key;
}

int search(int A[m], int key){
    int counter = 0;
    int hkey;
    do {
        hkey = h(key, counter);
    } while(A[hkey] != key && A[hkey] != 0 && counter++ < m);
    if(A[hkey] == key)
        return hkey;
    else
        return -1;
}

void printHash(int A[m]){
    printf("Table size: %d\n", m);
    for(int i = 0; i < m; ++i){
        if(A[i] != 0)
            printf("i: %d\tkey: %d\n", i, A[i]);
    }
}

int main(void){
    int A[m];
    init(A);
    insert(A, 1313);
    printHash(A);
    insert(A, 1314);
    printHash(A);
    insert(A, 1315);
    printHash(A);
    insert(A, 2000);
    printHash(A);
    insert(A, 2001);
    printHash(A);
    insert(A, 2002);
    printHash(A);
    printf("Value %d is in key %d\n", 2000, search(A, 2000));
    printf("Value %d is in key %d\n", 10, search(A, 10));
    printf("Value %d is in key %d\n", 1314, search(A, 1314));
    printf("Value %d is in key %d\n", 1313, search(A, 1313));
    printf("Value %d is in key %d\n", 337, search(A, 337));
    
    return 0;
}