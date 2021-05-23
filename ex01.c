#include <stdio.h>
#include <stdbool.h>

// Function declarations
void reverse(char []);
bool isPerfectSquare(int num);
void matrixMultiplication(int arr1[3][3], int arr2[3][3]);

void ascSelectionSort(int A[], int n);
void descSelectionSort(int A[], int n);

int main(void){

    // First task

    char str[1000];

    printf("Enter a string:\n");
    gets(str);

    reverse(str);


    // Second task
    
    int n;
    printf("Enter an integer:\n");
    scanf("%d", &n);

    isPerfectSquare(n);


    // Third Task
    
    int arr1[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int arr2[3][3] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    matrixMultiplication(arr1, arr2);


    // Fourth Task

    n = 6;
    int A[6] = {2, 10, 3, 22, 15, 12};

    ascSelectionSort(A, n);

    printf("Your array in ascending order is:\n");

    for(int i = 0; i < n; ++i){
        printf("%d ", A[i]);
    }

    printf("\n");

    descSelectionSort(A, n);

    printf("Your array in descending order is:\n");
    for(int i = 0; i < n; ++i){
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}

void reverse(char str[]){
    char temp;
    int lenInput = 0;

    for(; str[lenInput] != '\0'; ++lenInput);

    printf("Length of the string is: %d\n", lenInput);

    int i = 0, j = lenInput - 1;

    while(i < j){
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
    
    printf("string reversed is %s\n", str);

}


bool isPerfectSquare(int n){
    for(int i = 0; i <= n; ++i){
        if(n == i*i){
            printf("TRUE\n");
            return true;
        }
    }
    printf("FALSE");
    return false;
}


void matrixMultiplication(int arr1[3][3], int arr2[3][3]){
    int res[3][3];
    int sum;

    // Multiplication
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            sum = 0;
            for(int k = 0; k < 3; ++k){
                sum += arr1[i][k] * arr2[k][j];
                res[i][j] = sum;
            }
        }
    }

    // Output
    printf("\nMatrix Output:\n");
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            printf("%d  ", res[i][j]);
            if(j == 2)
                printf("\n");
        }
    }
}


void ascSelectionSort(int A[], int n){
    int x;

    for(int i = 0; i < n; ++i){
        for(int j = i + 1; j < n; ++j){
            if(A[j] < A[i]){
                x = A[j];
                A[j] = A[i];
                A[i] = x;
            }
        }
    }
}

void descSelectionSort(int A[], int n){
    int x = 0;
    
    for(int i = 0; i < n; ++i){
        for(int j = i + 1; j < n; ++j){
            if(A[i] < A[j]){
                x = A[i];
                A[i] = A[j];
                A[j] = x;
            }
        }
    }
}