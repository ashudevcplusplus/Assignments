#include <stdio.h>
#include <stdlib.h>
struct bst_node
{
    int d;
    struct bst_node *left;
    struct bst_node *right;
};

struct bst_node* root_node_bst;



struct bst_node* insert_node_bst(struct bst_node* root_node_bst, int val);

struct bst_node* delete_terminal_nodes(struct bst_node* root_node_bst);
void print_inorder_traversal(struct bst_node* root_node_bst);
struct bst_node* delete_terminal_nodes(struct bst_node* root_node_bst)
{
    if(root_node_bst==NULL)
    return NULL;
    if(root_node_bst->left == NULL && root_node_bst->right==NULL)
    {
        free(root_node_bst);
        return NULL;
    }
  root_node_bst->left=  delete_terminal_nodes(root_node_bst->left);
  root_node_bst->right=  delete_terminal_nodes(root_node_bst->right);
  return root_node_bst;
}

void print_inorder_traversal(struct bst_node* root_node_bst)
{
    if(root_node_bst==NULL)
    return;
    print_inorder_traversal(root_node_bst->left);
    printf("%d ",root_node_bst->d);

    print_inorder_traversal(root_node_bst->right);
}


struct bst_node* insert_node_bst(struct bst_node* root_node_bst, int val)
{
struct bst_node* h=(struct bst_node*)malloc(sizeof(struct bst_node));
h->d=val;
h->left=NULL;
h->right=NULL;
if(root_node_bst == NULL)
{
    root_node_bst=h;
    return root_node_bst;
}
else if(root_node_bst->d > val)
root_node_bst->left=insert_node_bst(root_node_bst->left,val);
else if(root_node_bst->d < val)
root_node_bst->right=insert_node_bst(root_node_bst->right,val);
return root_node_bst;

}

int main()
{
  int no_of_inputs, element;

  scanf("%d", &no_of_inputs);

  for (int i = 0; i < no_of_inputs; i++)
{
    scanf("%d", &element);
    root_node_bst = insert_node_bst(root_node_bst, element);
}
print_inorder_traversal(root_node_bst);
delete_terminal_nodes(root_node_bst);
printf("\n");
print_inorder_traversal(root_node_bst);



   return 0;
}
