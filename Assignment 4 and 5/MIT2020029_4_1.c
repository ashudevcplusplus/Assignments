#include <stdio.h>
#include <malloc.h>
#include <limits.h>

void perform_heapify_operation(int *heap, int i, int n){
    while(i != n){
      int left_child = i * 2;
      int right_child = 2 * i + 1;
      int min = i;
      if (left_child <= n && heap[left_child] < heap[i]) {
        min = left_child;
      }

      if (right_child <= n && heap[right_child] < heap[min]) {
        min = right_child;
      }

        if(min == i) return;

        int temp = heap[min];
        heap[min] = heap[i];
        heap[i] = temp;

        perform_heapify_operation(heap, min, n);
    }
}


int* build_heap(int* heap_using_array, int n){
    int* heap = (int*)malloc(sizeof(int)*(n + 1));
    heap[0] = INT_MIN;
    for (int i = 1; i <= n; i++){
        heap[i] = heap_using_array[i - 1];
    }

    for (int i = n / 2; i >= 1; i--){
        perform_heapify_operation(heap, i, n);
    }
    return heap;
}

int delete_min(int *heap_using_array, int size) {
  int element_deleted = heap_using_array[1];
  heap_using_array[1] = heap_using_array[size];
  perform_heapify_operation(heap_using_array, 1, size - 1);
  return element_deleted;
}

void print_heap(int *heap_using_array, int n) {
  for (int i = 1; i <= n; i++) {
    printf("%d ", heap_using_array[i]);
  }
  printf("\n");
}

int main() {
  int test_cases;
  scanf("%d", &test_cases);
  while (test_cases-- > 0) {
    int no_elements_heap, no_of_deletion;
    scanf("%d%d", &no_elements_heap, &no_of_deletion);
    int *heap_using_array = (int *)malloc(sizeof(int) * no_elements_heap);
    for (int i = 0; i < no_elements_heap; i++) {
      scanf("%d", (heap_using_array + i));
    }

    int *heap = build_heap(heap_using_array, no_elements_heap);
    int heap_size = no_elements_heap;
    print_heap(heap, heap_size);
    for (int i = 0; i < no_of_deletion; i++) {
      delete_min(heap, heap_size);
      heap_size--;
    }

    print_heap(heap, heap_size);
  }
    return 0;
}
