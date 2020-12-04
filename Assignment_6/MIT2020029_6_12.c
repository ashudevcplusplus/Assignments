
#include <stdio.h>
#include <malloc.h>

struct splay_tree_node {
    int value;
    struct splay_tree_node *left_node,  *right_node, *parent_node;
};

typedef struct splay_tree_node splay_tree_node;



void preorder(splay_tree_node *root){
    if(root){
        printf("%d ", root -> value);
        preorder(root -> left_node);
        preorder(root -> right_node);
    }
}

void inorder(splay_tree_node *root){
    if(root){
        inorder(root -> left_node);
        printf("%d ", root -> value);
        inorder(root -> right_node);
    }
}


splay_tree_node* LR(splay_tree_node *root){
    splay_tree_node* right_node = root -> right_node;
    root -> right_node = right_node -> left_node;
    if(root -> right_node){
        root -> right_node -> parent_node = root;
    }

    right_node -> parent_node = root -> parent_node;
    right_node -> left_node = root;
    root -> parent_node = right_node;
    if(right_node -> parent_node){
        if(right_node -> value <= right_node -> parent_node -> value){
            right_node -> parent_node -> left_node = right_node;
        }else{
            right_node -> parent_node ->right_node = right_node;
        }
    }
    return right_node;
}


splay_tree_node* RR(splay_tree_node *root){
    splay_tree_node *left_node = root -> left_node;
    root -> left_node = left_node -> right_node;
    if(root -> left_node){
       root -> left_node -> parent_node = root;
    }
    left_node -> parent_node = root -> parent_node;
    left_node -> right_node = root;
    root -> parent_node = left_node;
    if(left_node -> parent_node){
        if(left_node -> value <= left_node -> parent_node -> value){
            left_node -> parent_node -> left_node = left_node;
        }else{
            left_node -> parent_node ->right_node = left_node;
        }
    }
    return left_node;
}

splay_tree_node *LRR(splay_tree_node *root)
{
    root -> left_node = LR(root -> left_node);
    return RR(root);
}

splay_tree_node *RLR(splay_tree_node *root){
    root -> right_node = RR(root -> right_node);
    return LR(root);
}

int max(int a, int b){
    return  a >= b ? a : b;
}

void splay(splay_tree_node *root){
    while(root -> parent_node){

        if(root -> parent_node -> parent_node){
            if(root -> parent_node -> value <= root -> parent_node -> parent_node -> value) {
                if (root->value <= root->parent_node->value) {
                    root = RR(root->parent_node->parent_node);
                    root = RR(root);
                } else {
                    root = LRR(root -> parent_node -> parent_node);
                }
            }else{
                if (root -> value <= root -> parent_node -> value) {
                    root = RLR(root -> parent_node -> parent_node);
                } else {
                    root = LR(root->parent_node->parent_node);
                    root = LR(root);
                }
            }
        }else{
            if(root -> value <= root -> parent_node -> value){
                root = RR(root -> parent_node);
            }else{
                root = LR(root -> parent_node);
            }
        }
    }
}


splay_tree_node* insert(splay_tree_node *root, int data){
    if(!root){
        splay_tree_node* n = (splay_tree_node*)malloc(sizeof(splay_tree_node));
        n -> value = data;
        n -> left_node = NULL; n -> right_node = NULL; n -> parent_node = NULL;
        return n;
    }

    splay_tree_node *cur = root;
    splay_tree_node *parent_node = NULL;
    while(cur){
        parent_node = cur;
        if(data <= cur -> value){
            cur = cur -> left_node;
        }else{
            cur = cur -> right_node;
        }
    }

    splay_tree_node* datanode = (splay_tree_node *)malloc(sizeof(splay_tree_node));
    datanode -> value = data;
    datanode -> parent_node = parent_node;
    datanode -> left_node = NULL; datanode -> right_node = NULL;
    if(data <= parent_node -> value){
        parent_node -> left_node = datanode;
    }else{
        parent_node -> right_node = datanode;
    }
    splay(datanode);
    return datanode;
}

splay_tree_node* search(splay_tree_node *root, int target){
    if(!root) return root;
    splay_tree_node *cur = root;
    while(cur){
        if(cur -> value == target){
            break;
        }else if(target  <= cur -> value){
            cur = cur -> left_node;
        }else{
            cur = cur -> right_node;
        }
    }
    splay(cur);
    return cur;
}




int main(){
    splay_tree_node *root = NULL;
    int N, value;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    int k;
    scanf("%d", &k);
    while(k-- > 0){
        int value;
        scanf("%d", &value);
        root = search(root, value);
        preorder(root);
        printf("\n");
    }
    return 0;
}
/*
Input (stdin)

6
100 50 200 40 30 20
3
20 40 50

Your Output (stdout)
20 30 40 200 50 100
40 30 20 200 50 100
50 40 30 20 200 100

*/
