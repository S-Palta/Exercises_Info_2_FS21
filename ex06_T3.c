#include <stdio.h>
#include <stdlib.h>

struct node{
    int num;
    struct node *nextptr;
}*stnode;

void createNodeList(int n);
void displayList();
void insertNode(int num, int pos);
void deleteNode(int pos);
int FindElement(int FindElem);

int main(void){
    
    createNodeList(5);
    displayList();
    printf("\n\n");
    
    insertNode(42, 3);
    displayList();
    printf("\n\n");

    deleteNode(1);
    displayList();

    return 0;
}

void createNodeList(int n){
    struct node *fnNode, *tmp;
    int num, i;
    stnode = (struct node *)malloc(sizeof(struct node));
    if(stnode == NULL){
        printf("Memory cannot be allocated.\n");
    } else {
        printf("Input data for node 1: \n");
        scanf(" %d", &num);
        stnode->num = num;
        stnode->nextptr = NULL;
        tmp = stnode;

        for(i = 2; i <= n; i++){
            fnNode = (struct node *)malloc(sizeof(struct node));
            if(fnNode == NULL){
                printf("Memory cannot be allocated.\n");
                break;
            } else {
                printf("Input data for node %d:", i);
                scanf(" %d", &num);

                fnNode->num = num;
                fnNode->nextptr = NULL;

                tmp->nextptr = fnNode;
                tmp = tmp->nextptr;
            }
        }
    }
}

void displayList(){
    struct node *tmp;
    if(stnode == NULL){
        printf("No data found in the empty list.\n");
    } else {
        tmp = stnode;
        while(tmp != NULL){
            printf(" Data = %d\n", tmp->num);
            tmp = tmp->nextptr;
        }
    }
}

void insertNode(int num, int pos){
    int i;
    struct node *fnNode, *tmp;
    fnNode = (struct node *)malloc(sizeof(struct node));
    if(fnNode == NULL){
        printf(" Memory cannot be allocated.\n");
    } else {
        // Link the data part
        fnNode->num = num;
        fnNode->nextptr = NULL;

        tmp = stnode;
        for(i = 2; i <= pos-1; i++){
            tmp = tmp->nextptr;

            // check whether the link is long enough
            if(tmp == NULL){
                break;
            }
            if(tmp != NULL){
                fnNode->nextptr = tmp->nextptr;
                tmp->nextptr = fnNode;
            }
        }
    }
}

void deleteNode(int pos){
    struct node *toDelMid, *preNode;

    if(stnode == NULL){
        printf(" There is nothing I can delete right now.\n");
    } else {
        toDelMid = stnode;
        preNode = stnode;

        for(int i = 2; i <= pos; i++){
            preNode = toDelMid;
            toDelMid = toDelMid->nextptr;

            if(toDelMid == NULL){
                break;
            }
        }
        if(toDelMid != NULL){
            if(toDelMid == stnode)
                stnode = stnode->nextptr;
            
            preNode->nextptr = toDelMid->nextptr;
            toDelMid->nextptr = NULL;
            free(toDelMid);
        } else {
            printf(" Deletion is IMPOSSIBLE!!!!\n");
        }
    }
}

int FindElement(int FindElem){
    int ctr = 1;
    struct node *ennode = stnode;
    while(ennode->nextptr != NULL){
        if(ennode->num == FindElem)
            break;
        else {
            ctr++;
            ennode = ennode->nextptr;
        }
    }
    return ctr;
}