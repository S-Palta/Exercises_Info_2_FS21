#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node* left;
    struct node* right;
} bst;

struct node* lca_rec(bst* root, bst* n1, bst* n2){
    if(root == NULL)
        return NULL;
    if(root->val < n1->val && root->val < n2->val)
        return lca_rec(root->right, n1, n2);
    if(root->val > n1->val && root->val > n2->val)
        return lca_rec(root->left, n1, n2);
    return root;
}

int main(void){

    return 0;
}