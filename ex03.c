#include <stdio.h>

int WhatIDo(int A[1000], int n, int k);

int main(void){

    /*** First Task ***/
    int A[1000] = {2, 3, 5, 1, 8, 23, 54, 12, 56, 28};
    int n = 10;
    int k = 5;

    
    printf("The output of this function is: %d\n", WhatIDo(A, n, k));

    /*** Second Task ***/
    /* 
    f1(n) = O(n!), f2(n) = O(n^3), f3(n) = O(lgn), f4(n) = O(sqrt(n)), f5(n) = O(n^4), f6(n) = O(n), f7(n) = O(sqrt(n)), f8(n) = O(sqrt(n)), f9(n) = O(n^n), f10(n) = O(14400)
    
    f10(n) <= f3(n) <= f4(n) ~= f7(n) ~= f8(n) <= f2(n) <= f5(n) <= f1(n) <= f9(n)
    */

    /*** Third Task ***/
    /*
    for k = 1 and n = 2^k, T(n) = d*n + c*n*log(n), T(2^k) = d*2^k + c*(2^k)*k
    Base Case is k = 1 so T(2^k) = d*2 + c*2

    2*T((2^k)/2) + c*2^k which is equal to d*2 + c*2 for k = 1

    T((2^k)/2) = T(2^(k-1)) = T(2^0) = d
    */

    return 0;
}

int WhatIDo(int A[1000], int n, int k){
    int sum = 0;

    if(k > n)
        k -= n;

    for(int i = 0; i < k; ++i){
        int max_i = i;

        for(int j = i + 1; j < n; ++j){
            if(A[j] > A[max_i]){
                max_i = j;
            }
        }

        printf("A[max_i] is: %d\n", A[max_i]);
        sum += A[max_i];

        int swp = A[i];
        A[i] = A[max_i];
        A[max_i] = swp;
    }

    return sum;
}

/*  Runtime Analysis
c1 + c2*k + (c3 + c6 + c7 + c8 + c9)*(k-1) + c4*sum(ti, i from 1 to k) + c5*alpha*sum(ti - 1, i from i to k) + c10

*** Best Case ***
ti = 1, c2*k + c4*k + alpha*c5*k
= a*n + b
= O(k)

*** Worst Case ***
ti = k, c1 + c2*k + c4*(k*(k+1))/2 + alpha*c5*((k-1)*k)/2 + (c3 + c6 + c7 + c8 + c9)*(k-1) + c10
= a*n^2 + b*n + c
= O(k^2)

*** Special Cases ***

Array is empty -ok
if n != lengthArray, do for loop to count
if k > n, then do k = k - n  
*/