#include <stdio.h>

int tree_array_size = 20;
int heap_size = 0;
const int INF = 100000;

void swap( int *a, int *b ) {
  int t;
  t = *a;
  *a = *b;
  *b = t;
}

int find_right_child(int priority_queue_heap[], int index) {
  if((((2*index)+1) < tree_array_size) && (index >= 1))
    return (2*index)+1;
  return -1;
}

int get_left_child(int priority_queue_heap[], int index) {
  if (((2 * index) < tree_array_size) && (index >= 1))
    return 2 * index;
  return -1;
}

int get_parent(int A[], int index) {
  if ((index > 1) && (index < tree_array_size)) {
    return index/2;
  }
  return -1;
}

void perform_max_heapify(int priority_queue_heap[], int index) {
  int left_child_index = get_left_child(priority_queue_heap, index);
  int right_child_index = find_right_child(priority_queue_heap, index);
  int largest = index;

  if ((left_child_index <= heap_size) && (left_child_index>0)) {
    if (priority_queue_heap[left_child_index] > priority_queue_heap[largest]) {
      largest = left_child_index;
    }
  }

  if ((right_child_index <= heap_size && (right_child_index>0))) {
    if (priority_queue_heap[right_child_index] > priority_queue_heap[largest]) {
      largest = right_child_index;
    }
  }

  if (largest != index) {
    swap(&priority_queue_heap[index], &priority_queue_heap[largest]);
    perform_max_heapify(priority_queue_heap, largest);
  }
}

void build_max_heap(int priority_queue_heap[]) {
  int i;
  for(i=heap_size/2; i>=1; i--) {
    perform_max_heapify(priority_queue_heap, i);
  }
}

int maximum(int priority_queue_heap[]) { return priority_queue_heap[1]; }

int extract_max(int priority_queue_heap[]) {
  int maxm = priority_queue_heap[1];
  priority_queue_heap[1] = priority_queue_heap[heap_size];
  heap_size--;
  perform_max_heapify(priority_queue_heap, 1);
  return maxm;
}

void increase_key(int priority_queue_heap[], int index, int key) {
  priority_queue_heap[index] = key;
  while ((index > 1) &&
         (priority_queue_heap[get_parent(priority_queue_heap, index)] <
          priority_queue_heap[index])) {
    swap(&priority_queue_heap[index],
         &priority_queue_heap[get_parent(priority_queue_heap, index)]);
    index = get_parent(priority_queue_heap, index);
  }
}

void decrease_key(int A[], int index, int key) {
  A[index] = key;
  perform_max_heapify(A, index);
}

void insert_at_priority_queue(int A[], int key) {
  heap_size++;
  A[heap_size] = -1*INF;
  increase_key(A, heap_size, key);
}

void print_heap(int A[]) {
  int i;
  for(i=1; i<=heap_size; i++) {
    printf("%d ",A[i]);
  }
  printf("\n");
}

int main()
{
  int A[tree_array_size];
  int n;
  scanf("%d",&n);
  for (int i=0; i<n; i++)
  {
  int element;
  scanf("%d", &element);
  insert_at_priority_queue(A, element);

  }

  print_heap(A);
  return 0;
}  
