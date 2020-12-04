#include <stdio.h>
#include <stdlib.h>
struct node_BST
{
    int d;
    struct node_BST *left;
    struct node_BST *right;
};

struct node_BST* root;
struct node_BST *tree_1;
struct node_BST *tree_2;

struct node_BST* insert_node_in_bst(struct node_BST* root, int val);


int is_bst_same_or_not(struct node_BST* tree_1_bst,struct node_BST* tree_2_bst);
int is_bst_same_or_not(struct node_BST* tree_1_bst,struct node_BST* tree_2_bst)
{
    if(tree_1_bst==NULL && tree_2_bst==NULL)
    return 1;
    else if(tree_1_bst!=NULL && tree_2_bst==NULL)
    return 0;
    else if(tree_1_bst==NULL && tree_2_bst!=NULL)
    return 0;
    else
    {
if(tree_1_bst->d == tree_2_bst->d)
{ if(is_bst_same_or_not(tree_1_bst->left,tree_2_bst->left) && is_bst_same_or_not(tree_1_bst->right,tree_2_bst->right))
return 1;
else
return 0;
}

else
return 0;
    }
}


struct node_BST* insert_node_in_bst(struct node_BST* root, int val)
{
struct node_BST* h=(struct node_BST*)malloc(sizeof(struct node_BST));
h->d=val;
h->left=NULL;
h->right=NULL;
if(root == NULL)
{
    root=h;
    return root;
}
else if(root->d > val)
root->left=insert_node_in_bst(root->left,val);
else if(root->d < val)
root->right=insert_node_in_bst(root->right,val);
return root;

}

int main()
{
  int size_of_tree, flag_fn_returned, no_of_testcases, inserted_element;
  scanf("%d", &no_of_testcases);
  scanf("%d", &size_of_tree);
  for (int j = 0; j < no_of_testcases; j++)
  {
    tree_1 = NULL;
    tree_2 = NULL;
    for (int i = 0; i < size_of_tree; i++) {
      scanf("%d", &inserted_element);
      tree_1 = insert_node_in_bst(tree_1, inserted_element);
    }
    for (int i = 0; i < size_of_tree; i++) {
      scanf("%d", &inserted_element);
      tree_2 = insert_node_in_bst(tree_2, inserted_element);
    }
    flag_fn_returned = is_bst_same_or_not(tree_1, tree_2);
    if (flag_fn_returned == 1)
      printf("y\n");
    else
      printf("n\n");
  }

   return 0;
}
