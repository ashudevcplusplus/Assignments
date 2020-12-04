#include <stdio.h>
int count;
void heapify(int heap_using_array[], int n, int i) ;

int deleteElement(int *heap_using_array, int size_of_heap, int element_deletion) {
  int i;
  for (i = 0; i < size_of_heap; i++)
    if (heap_using_array[i] == element_deletion)
      break;

  if (i < size_of_heap) {
    size_of_heap = size_of_heap - 1;
    for (int j = i; j < size_of_heap; j++)
      heap_using_array[j] = heap_using_array[j + 1];
  }

  return size_of_heap;
}

void insertNode(int *heap_using_array, int size_of_heap, int Key) {
  size_of_heap = size_of_heap + 1;
  heap_using_array[size_of_heap - 1] = Key;
  //heapify(heap_using_array, size_of_heap, size_of_heap - 1);
}

void heapify(int *heap_using_array, int n, int i)
{
  int largest_element = i;
  int l = 2 * i + 1;
  int r = 2 * i + 2;
  if (l < n && heap_using_array[l] > heap_using_array[largest_element])
    largest_element = l;

  if (r < n && heap_using_array[r] > heap_using_array[largest_element])
    largest_element = r ;

  if (largest_element != i) {
    int temp = heap_using_array[i];
    heap_using_array[i] = heap_using_array[largest_element];
    heap_using_array[largest_element] = temp;
    count++;
    heapify(heap_using_array, n, largest_element);
  }
}


void buildHeap(int *heap_using_array, int n)
{
    int startIdx = (n / 2) - 1;
    for (int i = startIdx; i >= 0; i--) {
        heapify(heap_using_array, n, i);
    }
}


void printHeap(int *heap_using_array, int n)
{
    for (int i = 0; i < n; ++i)
        printf("%d ",heap_using_array[i]);
    printf("\n");
}



int main()
{

  int no_of_testcases;
  scanf("%d", &no_of_testcases);
  for (int i = 0; i < no_of_testcases; i++) {
    int input_digit, current_heap_size = 0, size_of_heap;
    scanf("%d", &size_of_heap);
    int heap_using_array[size_of_heap];
    for (int i = 0; i < size_of_heap; i++) {
      scanf("%d",&input_digit);
      insertNode(heap_using_array, current_heap_size, input_digit);
      current_heap_size++;

    }
      buildHeap(heap_using_array, current_heap_size);
      printf("%d\n", count);
      count=0;
  }

    return 0;
}
