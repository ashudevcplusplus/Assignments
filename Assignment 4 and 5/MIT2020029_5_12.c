#include <stdio.h>
#include <stdlib.h>
struct bst_node
{
    int d;
    struct bst_node *left;
    struct bst_node *right;
};

struct bst_node* root_node_bst;



struct bst_node* insert_node(struct bst_node* root_node_bst, int value);

void ancestor_of_given_key(struct bst_node* root_node_bst, int k);
void ancestor_of_given_key(struct bst_node* root_node_bst, int k)
{
    if(root_node_bst==NULL)
    return;
    if(root_node_bst->d == k)
    return ;
    else if(root_node_bst->left == NULL && root_node_bst->right == NULL)
    return;
    else
    {
        printf("%d ",root_node_bst->d);
        if(k < root_node_bst->d && root_node_bst->left!= NULL)
        ancestor_of_given_key(root_node_bst->left,k);
        if(k> root_node_bst->d && root_node_bst->right!=NULL)
        ancestor_of_given_key(root_node_bst->right,k);
    }
}


struct bst_node* insert_node(struct bst_node* root_node_bst, int value)
{
struct bst_node* h=(struct bst_node*)malloc(sizeof(struct bst_node));
h->d=value;
h->left=NULL;
h->right=NULL;
if(root_node_bst == NULL)
{
    root_node_bst=h;
    return root_node_bst;
}
else if(root_node_bst->d > value)
root_node_bst->left=insert_node(root_node_bst->left,value);
else if(root_node_bst->d < value)
root_node_bst->right=insert_node(root_node_bst->right,value);
return root_node_bst;

}

int main()
{
  int no_of_input, element, find_ancestor;

  scanf("%d", &no_of_input);

  for (int i = 0; i < no_of_input; i++) {
    scanf("%d", &element);
    root_node_bst = insert_node(root_node_bst, element);
   }

   scanf("%d", &find_ancestor);
   ancestor_of_given_key(root_node_bst, find_ancestor);

   return 0;
}
