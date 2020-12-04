#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* left, *right;
};
  struct node* root_node_bst;
  struct node* insert_node(struct node* root_node_bst, int val)
{
struct node* h=(struct node*)malloc(sizeof(struct node));
h->data=val;
h->left=NULL;
h->right=NULL;
if(root_node_bst == NULL)
{
    root_node_bst=h;
    return root_node_bst;
}
else if(root_node_bst->data > val)
root_node_bst->left=insert_node(root_node_bst->left,val);
else if(root_node_bst->data < val)
root_node_bst->right=insert_node(root_node_bst->right,val);
return root_node_bst;
}
void printGivenLevel(struct node* root_node_bst, int level);
int height(struct node* node);
struct node* newNode(int data);

void print_level_order_traversal(struct node* root_node_bst)
{
    int h = height(root_node_bst);
    int i;
    for (i=1; i<=h; i++)
        printGivenLevel(root_node_bst, i);
}


void printGivenLevel(struct node* root_node_bst, int level)
{
    if (root_node_bst == NULL)
        return;
    if (level == 1)
        printf("%d ", root_node_bst->data);
    else if (level > 1)
    {
        printGivenLevel(root_node_bst->left, level-1);
        printGivenLevel(root_node_bst->right, level-1);
    }
}

int height(struct node* node)
{
    if (node==NULL)
        return 0;
    else
    {

        int lheight = height(node->left);
        int rheight = height(node->right);

        if (lheight > rheight)
            return(lheight+1);
        else return(rheight+1);
    }
}

struct node* newNode(int data)
{
    struct node* node = (struct node*)
                        malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return(node);
}

int main()
{
  int no_of_inputs,element;

  scanf("%d", &no_of_inputs);

  for (int i = 0; i < no_of_inputs; i++) {
    scanf("%d", &element);

    root_node_bst = insert_node(root_node_bst, element);
  }

    printf("Level Order traversal of binary tree is : ");
    print_level_order_traversal(root_node_bst);

    return 0;
}
