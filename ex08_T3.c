#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void insert(struct TreeNode **root, int val){
    struct TreeNode *newTreeNode = NULL;
    struct TreeNode *prev = NULL;
    struct TreeNode *current = *root;

    newTreeNode = calloc(1, sizeof(struct TreeNode));
    newTreeNode->val = val;
    newTreeNode->left = NULL;
    newTreeNode->right = NULL;

    while (current != NULL){
        prev = current;
        if(val < current->val)
            current = current->left;
        else
            current = current->right;
    }
    if(prev == NULL){
        *root = newTreeNode;
    } else if(val < prev->val){
        prev->left = newTreeNode;
    } else {
        prev->right = newTreeNode;
    }
}

struct TreeNode *search(struct TreeNode *root, int val){
    struct TreeNode *current = root;
    
    while(current != NULL && current->val != val){
        if(current->val > val){
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return current;
}

int main(void){

    return 0;
}