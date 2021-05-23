#include <stdlib.h>
#include <stdio.h>

#define black 0
#define red 1

struct rb_node {
  	int key;
  	int color;
  	struct rb_node* left;
  	struct rb_node* right;
  	struct rb_node* parent;
};

struct rb_tree {
  	int bh;
  	struct rb_node *root;
  	struct rb_node *nil;
};

struct rb_tree* rb_initialize() {
  	struct rb_tree* tree;
  	struct rb_node* node;

  	tree = (struct rb_tree*) malloc(sizeof(struct rb_tree));

  	tree->nil = (struct rb_node*) malloc(sizeof(struct rb_node));
  	tree->nil->parent = tree->nil;
  	tree->nil->left = tree->nil;
  	tree->nil->right = tree->nil;
  	tree->nil->color = black;
  	tree->nil->key = -2;

  	tree->root = tree->nil;
  	tree->bh = 0;

  	return tree;
}

void rb_leftRotate(struct rb_tree* T, struct rb_node* x) {
  	struct rb_node* y;

    // x has no child
  	if(x->right == T->nil) return; 

    // y is x's right child
  	y = x->right;

    // y's left child is now x's right child
  	x->right = y->left;

    // x' parent now is y's
  	y->parent = x->parent;

    // y has left child
  	if (y->left != T->nil) {
        // x is y's left child's parent
    	  y->left->parent = x;
  	}

    // x is the root
  	if(x->parent == T->nil){
        // y is root
  		  T->root = y;
  	}

  	else{
        // x is left child
   		  if (x == x->parent->left) {
            // y replace x
    		    x->parent->left = y;
  		  } 
        // x is right child
  		  else {
            // y replace x
    		    x->parent->right = y;
  		  }
  	}

    // x is now y's left child
  	y->left = x;
    // y is x's parent
  	x->parent = y;
}

void rb_rightRotate(struct rb_tree* T, struct rb_node* x) {
  	struct rb_node* y;
  	if(x->left == T->nil) return;
  	y = x->left;
  	x->left = y->right;
  	y->parent = x->parent;
  
  	if(y->right != T->nil){
  		y->right->parent =x;
  	}
  	if (x->parent == T->nil) {
    	T->root = y;
  	}
  	else{
		if (x == x->parent->right) {
    		x->parent->right = y;
  		}
  		else {
    		x->parent->left = y;
  		}
  	}
  	y->right = x;
  	x->parent = y;
}

struct rb_node* rb_insertFixup(struct rb_tree* T, struct rb_node* z) {
  	struct rb_node* y;

  	while (z->parent->color == red) {
        /* non-mirrored cases */
        // z's parent is it's grandparent's left child
    	  if (z->parent == z->parent->parent->left) {
            // y is uncle, and a right child
     		    y = z->parent->parent->right;

            /* case 1 */ 
            // uncle is red and parent is red
      		  if (y->color == red) {   
                // parent and uncle change to black                
        		    z->parent->color = black;
        		    y->color = black;
                // grandparent changes to red
        		    z->parent->parent->color = red;
                // now the grandparent become z(child)
        		    z = z->parent->parent;
     		    } 

            // uncle is not red
     		    else {
            /* case 2 */
                // z is right child
        		    if (z == z->parent->right) {
                    // z's parent now is z             
          			    z = z->parent;
                    // triangle points to left, leftRotate(z)
          			    rb_leftRotate(T, z);
        		    }

                /* case 3 */
        		    z->parent->color = black;               
        		    z->parent->parent->color = red;
        		    rb_rightRotate(T, z->parent->parent);
      		  } 
    	  }

        /* mirrored cases */
        // z's parent is it's grandparent's right child
    	  else {   
            // y is uncle, and a right child                                 
      		  y = z->parent->parent->left;
            
            /* case 1m */
            // uncle is red
      		  if (y->color == red) {  
                // parent and uncle change to black                    
        		    z->parent->color = black;
        		    y->color = black;

                // grandparent changes to red 
        		    z->parent->parent->color = red;
                // now the grandparent become z(child)
        		    z = z->parent->parent;
     	 	    } 
            // uncle is black
     	 	    else {
                /* case 2m */
                // z is left child
        		    if (z == z->parent->left) {             
          		      z = z->parent;
                    // triangle points to right, rightRotate(z)
          		      rb_rightRotate(T, z);
        		    }

                /* case 3m */
        	      z->parent->color = black;               
        	      z->parent->parent->color = red;
        	      rb_leftRotate(T, z->parent->parent);
      		  }
    	  }
  	}

    // If root is red
    // Black height +1 
  	if (T->root->color == red) {
    	  T->bh += 1;
  	}

    // Root changes black
  	T->root->color = black;
}

void rb_insert(struct rb_tree* T, int key) {
    // oneDelayed = parents of insertPlace
  	struct rb_node* oneDelayed = T->nil;
  	struct rb_node* insertPlace = T->root;
  	struct rb_node* nodeToInsert =	(struct rb_node*) malloc(sizeof(struct rb_node));

    // Initialise the inserted node
  	nodeToInsert->key = key;
  	nodeToInsert->color = red;
  	nodeToInsert->left= T->nil;
  	nodeToInsert->right= T->nil;
  	nodeToInsert->parent= T->nil;

    // Iterate to find the place 
  	while (insertPlace != T->nil) {
        // move oneDelayed to current
        oneDelayed = insertPlace;

        // move the current to next by checking the condition
        if (nodeToInsert->key < insertPlace->key) {
      	   	insertPlace = insertPlace->left;
    	  }
    	  else {
      		  insertPlace = insertPlace->right;
    	  }
  	}

    // If you insert at the root (the first element)
  	if (oneDelayed == T->nil) {
    	  T->root = nodeToInsert;
  	}

    // Insert to the right
  	else if (oneDelayed->key < nodeToInsert->key) {
    	  oneDelayed->right = nodeToInsert;
    	  nodeToInsert->parent = oneDelayed;
  	}
  	else { // Insert to the left
    	  oneDelayed->left = nodeToInsert;
    	  nodeToInsert->parent = oneDelayed;
  	}

    // we need to fix the violation 
  	rb_insertFixup(T, nodeToInsert);
}


struct rb_node* rb_search(struct rb_tree* tree, int q) {
    struct rb_node* x = tree->root;

    // Tree is empty
    if (x == tree->nil)
        return x;

    // iterate ro find q
    while (x->key != q) {
        if (q < x->key)
            x = x->left;
        else
            x = x->right;

        // q doesn't exist in the tree
        if (x == tree->nil)
            return x;
    }

    return x;
}

void rb_printRecursive(struct rb_node *root, struct rb_tree *tree) {
  	if (root == tree->nil) {
    	return;
  	}
  	rb_printRecursive(root->left, tree);
  	if (root->left != tree->nil) {
    	printf(" \"%d (%s)\" -- \"%d (%s)\"\n", root->key,	
    		(root->color==red?"RED":"BLACK"), root->left->key, 
    		(root->left->color==red?"RED":"BLACK"));
  	}
  	rb_printRecursive(root->right, tree);
  	if (root->right != tree->nil) {
    	printf(" \"%d (%s)\" -- \"%d (%s)\"\n", root->key,
           (root->color==red?"RED":"BLACK"),
           root->right->key, (root->right->color==red?"RED":"BLACK"));
  	}
}

void rb_print(struct rb_tree *tree) {
  	printf("graph g {\n");
  	rb_printRecursive(tree->root, tree);
 	  printf("}\n");
}

int main(int argc, char **argv) {
  	struct rb_tree *T;
  	T = rb_initialize();

  	rb_insert(T, 5);
  	rb_insert(T, 90);
  	rb_insert(T, 20);
  	rb_print(T);
  	rb_rightRotate(T, rb_search(T, 20));
  	rb_print(T);
  	rb_leftRotate(T, rb_search(T, 5));
  	rb_print(T); 
  	rb_insert(T, 60);
  	rb_insert(T, 30);
  	rb_print(T);
  	rb_rightRotate(T, rb_search(T, 90));
  	rb_print(T);
  	return 0;
}
// Linux, Mac: gcc task09_3.c -o task09_3; ./task09_3
// Windows: gcc task09_3.c -o task09_3; task09_3
