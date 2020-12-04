
#include <stdio.h>
#include <malloc.h>

struct tree_node {
    int value;
    struct tree_node *left,  *right;
};

typedef struct tree_node tree_node;

tree_node* leftRotation(tree_node *root_node){
    tree_node* right = root_node -> right;
    root_node -> right = right -> left;
    right -> left = root_node;
    return right;
}


tree_node* rightRotation(tree_node *root_node){
    tree_node *left = root_node -> left;
    root_node -> left = left -> right;
    left -> right = root_node;
    return left;
}

tree_node *leftRightRotation(tree_node *root_node)
{
    root_node -> left = leftRotation(root_node -> left);
    return rightRotation(root_node);
}


tree_node *rightLeftRotation(tree_node *root_node){
    root_node -> right = rightRotation(root_node -> right);
    return leftRotation(root_node);
}

int max(int a, int b){
    return  a >= b ? a : b;
}


int height(tree_node *root_node)
{
    if(root_node){
        return 1 + max(height(root_node -> left), height(root_node -> right));
    }else{
        return 0;
    }
}


tree_node* insert_into_AVL(tree_node *root_node, int data){

    if(!root_node){
        tree_node* node = (tree_node*)malloc(sizeof(tree_node));
        node -> value = data;
        node -> left = NULL;
        node -> right = NULL;
        return node;
    }else if(data <= root_node -> value){
        root_node -> left = insert_into_AVL(root_node -> left, data);
    }else{
        root_node -> right = insert_into_AVL(root_node -> right, data);
    }

    int lh = height(root_node -> left);
    int rh = height(root_node -> right);
    if(lh - rh >= 2){
        if(data <= root_node -> left -> value){
            return rightRotation(root_node);
        }else{
            return leftRightRotation(root_node);
        }
    }else if(lh - rh <= -2){
        if(data <= root_node -> right -> value){
            return rightLeftRotation(root_node);
        }else{
            return leftRotation(root_node);
        }
    }
    return root_node;
}

void pre_order_traversal(tree_node *root_node){
    if(root_node){
        printf("%d ", root_node -> value);
        pre_order_traversal(root_node -> left);
        pre_order_traversal(root_node -> right);
    }
}

tree_node* perform_balancing(tree_node *root_node){
    int lh = height(root_node -> left);
    int rh = height(root_node -> right);
    if(lh - rh >= 2){
        int llh = height(root_node -> left -> left);
        int lrh = height(root_node -> left -> right);
        if(llh >= lrh){
            return rightRotation(root_node);
        }else{
            return leftRightRotation(root_node);
        }
    }else if(lh - rh <= -2){
        int rlh = height(root_node -> right -> left);
        int rrh = height(root_node -> right -> right);
        if(rrh >= rlh){
            return leftRotation(root_node);
        }else{
            return rightLeftRotation(root_node);
        }
    }
    return root_node;
}

tree_node* predecessor(tree_node *root_node, tree_node *target_node){
    if(root_node -> right){
        root_node -> right = predecessor(root_node -> right, target_node);
        return perform_balancing(root_node);
    }else{
        if(!(root_node -> left) && !(root_node -> right)){
            target_node -> value = root_node -> value;
            return NULL;
        }else{
            target_node -> value = root_node -> value;
            return root_node -> left;
        }
    }
}

tree_node* successor(tree_node *root_node, tree_node *target_node){
    if(root_node -> left){
        root_node -> left = predecessor(root_node -> left, target_node);
        return perform_balancing(root_node);
    }else{
        if(!(root_node -> left) && !(root_node -> right)){
            target_node -> value = root_node -> value;
            return NULL;
        }else{
            target_node -> value = root_node -> value;
            return root_node -> right;
        }
    }
}

tree_node* delete(tree_node *root_node, int ser){
    if(!root_node) return NULL;
    if(root_node -> value == ser && !(root_node -> left) && !(root_node -> right)){
        return NULL;
    }
    if(root_node -> value == ser){
        if((root_node -> right)){
            root_node -> right = successor(root_node -> right, root_node);
        }else{
            root_node -> left = predecessor(root_node -> left, root_node);
        }
    }else if(ser <= root_node -> value){
        root_node -> left = delete(root_node -> left, ser);
    }else{
        root_node -> right = delete(root_node -> right, ser);
    }


    return perform_balancing(root_node);
}

int main(){
    tree_node *root_node = NULL;
    int N, value;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &value);
        root_node = insert_into_AVL(root_node, value);
    }

    pre_order_traversal(root_node);
    printf("\n");
    int del = 0;
    scanf("%d", &del);

    for (int i = 0; i < del; i++){
        int ele;
        scanf("%d", &ele);
        root_node = delete(root_node, ele);
        pre_order_traversal(root_node);
        printf("\n");
    }

    printf("\n");
    return 0;
}
/*
9
9 5 10 0 6 11 -1 1 2
5
10 5 -1 6 11

Your Output (stdout)
9 1 0 -1 5 2 6 10 11
1 0 -1 9 5 2 6 11
1 0 -1 9 6 2 11
6 1 0 2 9 11
9 1 0 2 11
1 0 9 2 */
