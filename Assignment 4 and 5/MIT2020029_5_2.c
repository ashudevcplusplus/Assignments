#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    struct node *left_child, *right_child;
};


struct node* newNode(int item)
{
    struct node* temp
        = (struct node*)malloc(sizeof(struct node));
    temp->key = item;
    temp->left_child = temp->right_child = NULL;
    return temp;
}

void inorder_print(struct node* root)
{
    if (root != NULL) {
        inorder_print(root->left_child);
        printf("%d_", root->key);
        inorder_print(root->right_child);
    }
}
void preorder_print(struct node* root)
{
    if (root != NULL) {
        printf("%d_", root->key);
        preorder_print(root->left_child);
        preorder_print(root->right_child);
    }
}
void postorder_print(struct node* root)
{
    if (root != NULL) {
        postorder_print(root->left_child);
        postorder_print(root->right_child);
        printf("%d_", root->key);
    }
}

struct node* insert(struct node* node, int key)
{

    if (node == NULL)
        return newNode(key);
    if (key < node->key)
        node->left_child = insert(node->left_child, key);
    else if (key > node->key)
        node->right_child = insert(node->right_child, key);

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

  preorder_print(root_node);
  printf("\n");
  inorder_print(root_node);
  printf("\n");
  postorder_print(root_node);
  return 0;
}
