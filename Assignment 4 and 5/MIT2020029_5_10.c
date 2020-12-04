#include <stdio.h>
#include <stdlib.h>
int count;
struct node {
    int key;
    struct node *left, *right;
};

void mirror(struct node *root_node) {
  if (root_node == NULL)
    return;
  else
  {
    struct node* temp;

    mirror(root_node->left);
    mirror(root_node->right);

    temp = root_node->left;
    root_node->left = root_node->right;
    root_node->right = temp;
  }
}

void inOrder(struct node *root_node) {
  if (root_node == NULL)
    return;

  inOrder(root_node->left);
  printf("%d ", root_node->key);
  inOrder(root_node->right);
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
  printf("Inorder traversal of the constructed"
           " tree is \n");
  inOrder(root_node);

  /* Convert tree to its mirror */
  mirror(root_node);

  /* Print inorder traversal of the mirror tree */
  printf("\nInorder traversal of the mirror tree"
         " is \n");
  inOrder(root_node);
  return 0;
}
