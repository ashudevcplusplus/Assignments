
#include <stdio.h>
#include <malloc.h>

struct splay_tree_node {
    int val;
    struct splay_tree_node *left,  *right, *parent;
};

typedef struct splay_tree_node splay_tree_node;

void preorder(splay_tree_node *root_node){
    if(root_node){
        printf("%d ", root_node -> val);
        preorder(root_node -> left);
        preorder(root_node -> right);
    }
}

void inorder(splay_tree_node *root_node){
    if(root_node){
        inorder(root_node -> left);
        printf("%d ", root_node -> val);
        inorder(root_node -> right);
    }
}





splay_tree_node* rightRotation(splay_tree_node *root_node){
    splay_tree_node *left = root_node -> left;
    root_node -> left = left -> right;
    if(root_node -> left){
       root_node -> left -> parent = root_node;
    }
    left -> parent = root_node -> parent;
    left -> right = root_node;
    root_node -> parent = left;
    if(left -> parent){
        if(left -> val <= left -> parent -> val){
            left -> parent -> left = left;
        }else{
            left -> parent ->right = left;
        }
    }
    return left;
}

splay_tree_node* leftRotation(splay_tree_node *root_node){
    splay_tree_node* right = root_node -> right;
    root_node -> right = right -> left;
    if(root_node -> right){
        root_node -> right -> parent = root_node;
    }

    right -> parent = root_node -> parent;
    right -> left = root_node;
    root_node -> parent = right;
    if(right -> parent){
        if(right -> val <= right -> parent -> val){
            right -> parent -> left = right;
        }else{
            right -> parent ->right = right;
        }
    }
    return right;
}
splay_tree_node *leftRightRotation(splay_tree_node *root_node)
{
    root_node -> left = leftRotation(root_node -> left);
    return rightRotation(root_node);
}


splay_tree_node *rightLeftRotation(splay_tree_node *root_node){
    root_node -> right = rightRotation(root_node -> right);
    return leftRotation(root_node);
}




splay_tree_node* insert_node_tree(splay_tree_node *root_node, int data){
    if(!root_node){
        splay_tree_node* n = (splay_tree_node*)malloc(sizeof(splay_tree_node));
        n -> val = data;
        n -> left = NULL; n -> right = NULL; n -> parent = NULL;
        return n;
    }

    splay_tree_node *cur = root_node;
    splay_tree_node *parent = NULL;
    while(cur){
        parent = cur;
        if(data <= cur -> val){
            cur = cur -> left;
        }else{
            cur = cur -> right;
        }
    }

    splay_tree_node* datanode = (splay_tree_node *)malloc(sizeof(splay_tree_node));
    datanode -> val = data;
    datanode -> parent = parent;
    datanode -> left = NULL; datanode -> right = NULL;
    if(data <= parent -> val){
        parent -> left = datanode;
    }else{
        parent -> right = datanode;
    }
    splay(datanode);
    return datanode;
}

int max(int a, int b){
    return  a >= b ? a : b;
}

void splay(splay_tree_node *root_node){
    while(root_node -> parent){
        if(root_node -> parent -> parent){
            if(root_node -> parent -> val <= root_node -> parent -> parent -> val) {
                if (root_node->val <= root_node->parent->val) {
                    root_node = rightRotation(root_node->parent->parent);
                    root_node = rightRotation(root_node);
                } else {
                    root_node = leftRightRotation(root_node -> parent -> parent);
                }
            }else{
                if (root_node -> val <= root_node -> parent -> val) {
                    root_node = rightLeftRotation(root_node -> parent -> parent);
                } else {
                    root_node = leftRotation(root_node->parent->parent);
                    root_node = leftRotation(root_node);
                }
            }
        }else{
            if(root_node -> val <= root_node -> parent -> val){
                root_node = rightRotation(root_node -> parent);
            }else{
                root_node = leftRotation(root_node -> parent);
            }
        }
    }
}
int main(){
    splay_tree_node *root_node = NULL;
    int N, val;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &val);
        root_node = insert_node_tree(root_node, val);
    }

    int k;
    scanf("%d", &k);
    while(k-- > 0){
        int val;
        scanf("%d", &val);
        root_node = insert_node_tree(root_node, val);
        preorder(root_node);
        printf("\n");
    }
    return 0;
}
/*
Input (stdin)
6
100 50 200 40 30 20
3
25 55 35

Your Output (stdout)
25 20 30 40 200 50 100
55 30 25 20 40 50 200 100
35 30 25 20 55 40 50 200 100
*/
