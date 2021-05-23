#include <stdio.h>
#include <stdlib.h>

int find_closer_in_two_values(int a, int b, int t){
    if(abs(a - t) < abs(b - t)){
        return a;
    }
    return b;
}

int find_closest(int A[], int n, int t){
    if(t <= A[0]){
        return A[0];
    }
    if(t >= A[n - 1]){
        return A[n - 1];
    }
    // Perform binary search
    int i = 0;
    int j = n;
    int mid = 0;
    while (i < j){
        mid = (i + j) / 2;
        if(t == A[mid]){
            return A[mid];
        }
        if(t < A[mid]){
            // In this case, target is smaller than A[mid], all elements after index mid are excluded. Binary search paradigm is applied.
            if(mid > 0 && t > A[mid - 1]){
                return find_closer_in_two_values(A[mid - 1], A[mid], t);
            }
            j = mid;
        } else {
            if(mid < n -1 && t < A[mid + 1]){
                return find_closer_in_two_values(A[mid], A[mid + 1], t);
            }
            i = mid + 1;
        }
    }
    return A[mid];
}

int main(void){
    int A[100];
    int i = 0;
    int t = 0;
    int n = 0;

    printf("Values of the array separated by spaces (non-number to stop): ");

    while (scanf("%d", &A[i]) == 1){
        i++;
    }
    n = i;
    scanf("%*s");
    printf("\nTarget t: ");
    scanf("%d", &t);

    printf("\nResult: ");

    printf("%d\n", find_closest(A, n, t));

    return 0;
}