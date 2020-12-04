
#include <stdio.h>
#include <malloc.h>

struct TreeNode {
    int val;
    struct TreeNode *left,  *right;
};

typedef struct TreeNode TreeNode;
TreeNode* perform_left_rotation(TreeNode *root_node){
    if(!(root_node -> left))
        return root_node;
    else{
        TreeNode* right = root_node -> right;
        root_node -> right = right -> left;
        right -> left = root_node;
        return right;
    }
}
void preorder_traversal(TreeNode *root_node){
    if(root_node){
        printf("%d ", root_node -> val);
        preorder_traversal(root_node -> left);
        preorder_traversal(root_node -> right);
    }
}
TreeNode* insert_node(TreeNode *root_node, int val){
    if(root_node){
        if(val <= root_node -> val){
            root_node -> left = insert_node(root_node -> left, val);
        }else{
            root_node -> right = insert_node(root_node -> right, val);
        }
        return root_node;
    }else{
        TreeNode *node = (TreeNode*)malloc(sizeof(TreeNode));
        node -> val = val;
        node -> left = NULL;
        node -> right = NULL;
        return node;
    }
}





void inorder_traversal(TreeNode *root_node){
    if(root_node){
        inorder_traversal(root_node -> left);
        printf("%d ", root_node -> val);
        inorder_traversal(root_node -> right);
    }
}

int main(){
    TreeNode* root_node = NULL;
    int N, val;
    scanf("%d", &N);
    for (int i = 0; i < N; i++){
        scanf("%d", &val);
        root_node = insert_node(root_node, val);
    }

    inorder_traversal(root_node);
    printf("\n");
    root_node = perform_left_rotation(root_node);
    preorder_traversal(root_node);
    return 0;
}
