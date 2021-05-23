#include <stdio.h>
#include <stdlib.h>

int numberOfInversions(int A[], int n){
    int res = ((1/2) * n^2) - ((1/2) * n);
    return res;
}

int main(void){
    int A[100] = {3, 2, 1};
    int n = 3;

    printf("%d\n", numberOfInversions(A, n));

    return 0;
}