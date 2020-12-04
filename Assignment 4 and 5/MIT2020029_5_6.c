#include <stdio.h>
#include <stdlib.h>
int count;
struct node {
    int key;
    struct node *left, *right;
};

unsigned int calculate_sum_of_leaf_node(struct node* node)
{
  if(node == NULL)
    return 0;
  if(node->left == NULL && node->right==NULL)
  {
      count=count+ node->key;
    return 1;
  }

  else
    return calculate_sum_of_leaf_node(node->left)+
           calculate_sum_of_leaf_node(node->right);
}

struct node* newNode(int item)
{
    struct node* temp
        = (struct node*)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

struct node* insert(struct node* node, int key)
{

    if (node == NULL)
        return newNode(key);
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    return node;
}

int main()
{

  int no_elements_BST, element;
  struct node *root_node = NULL;
  scanf("%d", &no_elements_BST);
  for (int i = 0; i < no_elements_BST; i++) {
    scanf("%d", &element);
    root_node = insert(root_node, element);
  }
  calculate_sum_of_leaf_node(root_node);
  printf("%d ", count);
  return 0;
}
