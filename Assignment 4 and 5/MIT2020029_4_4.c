#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

struct heap_node_BST{
    int node_value;
    struct heap_node_BST *left_child, *right_child, *parent_node;
};

typedef struct heap_node_BST heap_node_BST;

heap_node_BST *root = NULL;
int heapsize = 0;


int find_left_most_level(heap_node_BST *root_node, int current_level) {
  if (!(root_node->left_child) && !(root_node->right_child))
    return current_level;
  if (!(root_node->right_child))
    return current_level + 1;
  return find_left_most_level(root_node->right_child, current_level + 1);
}

int find_right_most_level(heap_node_BST *root_node, int current_level) {
  if (!root_node) {
    return current_level;
  } else {
    return find_right_most_level(root_node->right_child, current_level + 1);
  }
}

void breath_first_search()
{
    int queuesize = 1000;
    heap_node_BST **queue_BFS = (heap_node_BST**) malloc(sizeof(heap_node_BST*) * queuesize);

    for (int i = 0; i < queuesize; i++){
        queue_BFS[i] = NULL;
    }
    queue_BFS[0] = root;
    int front = 0, rear = 0;
    while(queue_BFS[front]){
        printf("%d ", queue_BFS[front] -> node_value);
        if(queue_BFS[front] -> left_child){
            if((rear + 1) % queuesize == front) {
                printf("overflow");
                exit(1);
            }
            rear = (rear + 1) % queuesize;
            queue_BFS[rear] = queue_BFS[front] -> left_child;
        }
        if(queue_BFS[front] -> right_child){
            if((rear + 1) % queuesize == front) {
                printf("overflow");
                exit(1);
            }
            rear =  (rear + 1) % queuesize;
            queue_BFS[rear] = queue_BFS[front] -> right_child;
        }
        front = (front + 1) % queuesize;
    }
    printf("\n");
}

void perform_heapify(heap_node_BST *root_node_bst) {
  heap_node_BST *min = NULL;
  while (root_node_bst) {
    min = root_node_bst;
    if ((root_node_bst->left_child) && (root_node_bst->left_child->node_value) < min->node_value) {
      min = root_node_bst->left_child;
    }
    if ((root_node_bst->right_child) && (root_node_bst->right_child->node_value) < min->node_value) {
      min = root_node_bst->right_child;
    }

    if (min == root_node_bst)
      return;
    int temp = min->node_value;
    min->node_value = root_node_bst->node_value;
    root_node_bst->node_value = temp;
    root_node_bst = min;
  }
}

void del_min_heap(heap_node_BST *r){
    if(!(r -> left_child) && !(r -> right_child)){
        heap_node_BST *par = r -> parent_node;
        if(r == root){
            root = NULL;
            free(r);
            return;
        }else if((par -> right_child)){
            par -> right_child = NULL;
            root -> node_value = r -> node_value;
            free(r);
            heapsize--;
        }else{
            par -> left_child = NULL;
            root -> node_value = r -> node_value;
            free(r);
            heapsize--;
        }
        perform_heapify(root);
    }else if(!(r -> right_child)){
        del_min_heap(r -> left_child);
    }else{
        int left_child = find_left_most_level(r -> left_child, 0);
        int right_child = find_left_most_level(r -> right_child, 0);
        if(left_child == right_child){
            del_min_heap(r -> right_child);
        }else{
            del_min_heap(r -> left_child);
        }
    }
}

void perform_heapify_reverse(heap_node_BST *child){
    while(child -> parent_node){
        heap_node_BST* parent_node = child -> parent_node;
        if(parent_node -> node_value > child ->  node_value){
            int temp = child -> node_value;
            child -> node_value = parent_node -> node_value;
            parent_node -> node_value = temp;
        }
        child = parent_node;
    }
}

void insert_in_heap(heap_node_BST *r, int node_value){
    if(!r){
        r = (heap_node_BST *) malloc (sizeof(heap_node_BST));
        r -> node_value = node_value;
        r -> left_child = r -> right_child = r -> parent_node = NULL;
        root = r;
        heapsize++;
    }else if(!(r -> left_child)){
        heap_node_BST *temp = (heap_node_BST *) malloc (sizeof(heap_node_BST));
        temp -> node_value = node_value;
        temp -> left_child = temp -> right_child = NULL;
        temp -> parent_node = r;
        r -> left_child = temp;
        heapsize++;
        perform_heapify_reverse(temp);
    }else if(!(r -> right_child)){
        heap_node_BST *temp = (heap_node_BST *) malloc (sizeof(heap_node_BST));
        temp -> node_value = node_value;
        temp -> left_child = temp -> right_child = NULL;
        temp -> parent_node = r;
        r -> right_child = temp;
        heapsize++;
        perform_heapify_reverse(temp);
    }else{
        int leftLevel = find_right_most_level(r -> left_child, 0);
        int righLevel = find_right_most_level(r -> right_child, 0);
        if(leftLevel <= righLevel){
            insert_in_heap(r -> left_child, node_value);
        }else {
            insert_in_heap(r -> right_child, node_value);
        }
    }
}

int isEmpty(){
    if(root) return 0;
    else return 1;
}

int isFull(){
    int t = heapsize + 1;
    int numberOfSetBits = 0;
    printf("%d", t);
    for (int i = 0; i < 31; i++){
        if((t & (1 << i))){
            numberOfSetBits++;
        }
    }
    return numberOfSetBits == 1 ? 1 : 0;
}

int main()
{
  int test_cases, input_choice, inserted_value;
  scanf("%d", &test_cases);
  while (test_cases-- > 0) {
    scanf("%d", &input_choice);
    if (input_choice == 1) {
      scanf("%d", &inserted_value);
      insert_in_heap(root, inserted_value);
      breath_first_search(root);
    } else if (input_choice == 2) {
      if (!root) {
        printf("Empty\n");
      } else {
        del_min_heap(root);
        breath_first_search(root);
      }
    } else if (input_choice == 3) {
      if (isFull()) {
        printf("Full\n");
      } else {
        printf("Not Full\n");
      }
    } else if (input_choice == 4) {
      if (isEmpty()) {
        printf("Empty\n");
      } else {
        printf("Not Empty\n");
      }
    } else {
      break;
    }
    }
    return 0;
}
