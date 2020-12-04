#include <stdio.h>
#include <stdlib.h>
struct node {
    int key;
    struct node *left, *right;
};

unsigned int getLeafCount(struct node* node)
{
  if(node == NULL)
    return 0;
  if(node->left == NULL && node->right==NULL)
    return 1;
  else
    return getLeafCount(node->left)+
           getLeafCount(node->right);
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
printf("%d ", getLeafCount(root_node));
  return 0;
}    
