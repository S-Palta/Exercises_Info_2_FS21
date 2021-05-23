#include <stdio.h>
#include <stdlib.h>

// Functions Declarations

int exponent(int x, int pow);

int sequence(int n);

int iterativeFirstUpper(char str[1000]);
int recursiveFirstUpper(char str[1000], int pos);


int pascal(int i, int j);
void printPascal(int n);
int recursive_find_indent(int current_row, int total_rows);
void format_print_pascal(int n);

int main(void){
    /******* First task *******/
    
    int x = 0, pow = 0;

    // Get user input
    printf("Please enter the base: ");
    scanf("%d", &x);
    printf("\nPlease enter the power: ");
    scanf("%d", &pow);
    printf("\n%d", pow);

    printf("\nThe result is: %d", exponent(x, pow));

    /******* Second task *******/
    int n = 0;
    printf("\nEnter a number for sequence: ");
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        printf("%d ", sequence(i));
    }
    printf("\n");

    /******* Third Task *******/
    
    char str[1000] = "weAAAe";
    int pos = 0;
    iterativeFirstUpper(str);
    recursiveFirstUpper(str, pos);

    /******* Fourth Task *******/
    
    printPascal(5);
    format_print_pascal(5);

    return 0;
}


int exponent(int x, int pow){
    if(pow != 0){
        return (x * exponent(x, pow - 1));
    } else {
        return 1;
    }
}


int sequence(int n){
    if(n == 1 || n == 2){
        return n;
    }

    int a_n_minus_1 = sequence(n - 1);
    int a_n_minus_2 = sequence(n - 2);

    if(a_n_minus_1 % 3 == 0){
        a_n_minus_1 /= 3;
    }

    return a_n_minus_1 + a_n_minus_2;
}


int iterativeFirstUpper(char str[1000]){
    for(int i = 0; i < 1000; ++i){
        if (str[i] >= 'A' && str[i] <= 'Z'){
            printf("\nThe first uppercase comes at position %d", i + 1);
            return i;
        }
    }
    return -1;
}

int recursiveFirstUpper(char str[1000], int pos){
    if(str[pos] == '\0')
        return -1;
    if(str[pos] >= 'A' && str[pos] <= 'Z'){
        printf("\nThe first uppercase appears at position %d", pos + 1);
        return pos + 1;
    }
    return recursiveFirstUpper(str, pos + 1);
}


int pascal(int i, int j){
    if(i == j || j == 0){
        return 1;
    }
    return pascal(i - 1, j - 1) + pascal(i - 1, j);
}

void printPascal(int n){
    printf("\n");
    for(int i = 0; i <= n; ++i){
        printf("Row %d: ", i);
        for(int j = 0; j <= i; ++j){
            printf("%d ", pascal(i, j));
        }
        printf("\n");
    }
}

int recursive_find_indent(int current_row, int total_rows){
    if(current_row == total_rows){
        return 0;
    }
    return 2 + recursive_find_indent(current_row + 1, total_rows);
}

void format_print_pascal(int n){
    int row, column;
    for(row = 0; row < n; ++row){
        printf("%*c", recursive_find_indent(row, n), ' ');
        for(column = 0; column <= row; ++column){
            printf("%d ", pascal(row, column));
        }
        printf("\n");
    }
}