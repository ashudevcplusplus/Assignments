
#include <stdio.h>
#include <malloc.h>

struct tree_node {
    int value;
    struct tree_node *left_child,  *right_child;
};

typedef struct tree_node tree_node;

void preorder_traversal(tree_node *root_node){
    if(root_node){
        printf("%d ", root_node -> value);
        preorder_traversal(root_node -> left_child);
        preorder_traversal(root_node -> right_child);
    }
}
tree_node* perform_rotation(tree_node *root_node){
    if(!(root_node -> left_child))
        return root_node;
    else{
        tree_node* left_child = root_node -> left_child;
        root_node -> left_child = left_child -> right_child;
        left_child -> right_child = root_node;
        return left_child;
    }
}

void inorder_traversal(tree_node *root_node){
    if(root_node){
        inorder_traversal(root_node -> left_child);
        printf("%d ", root_node -> value);
        inorder_traversal(root_node -> right_child);
    }
}

tree_node* insert_a_node(tree_node *root_node, int value){
    if(root_node){
        if(value <= root_node -> value){
            root_node -> left_child = insert_a_node(root_node -> left_child, value);
        }else{
            root_node -> right_child = insert_a_node(root_node -> right_child, value);
        }
        return root_node;
    }else{
        tree_node *node = (tree_node*)malloc(sizeof(tree_node));
        node -> value = value;
        node -> left_child = NULL;
        node -> right_child = NULL;
        return node;
    }
}





int main(){
    tree_node* root_node = NULL;
    int N, value;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &value);
        root_node = insert_a_node(root_node, value);
    }

    inorder_traversal(root_node);
    printf("\n");
    root_node = perform_rotation(root_node);
    preorder_traversal(root_node);
    return 0;
}
