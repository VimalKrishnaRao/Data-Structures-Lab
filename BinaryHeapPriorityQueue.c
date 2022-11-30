#include <stdio.h>
int size = 0;
void swap(int *a, int *b) 
{
  int temp = *b;
  *b = *a;
  *a = temp;
}
void maxheapify(int array[], int size, int k) 
{
  if (size == 1) 
  {
    printf("Single element in the heap");
  } 
  else 
  {
    int max = k;
    int l = 2 * k;
    int r = 2 * k + 1;
    if (l < size && array[l] > array[k])
        max = l;
    else 
        max = k;
    if (r < size && array[r] > array[max])
      max = r;
    if (max!= k) 
    {
      swap(&array[k], &array[max]);
      maxheapify(array, size, max);
    }
  }
}
void insert(int array[], int newNum) 
{
  if (size == 0) 
  {
    array[0] = newNum;
    size += 1;
  } 
  else 
  {
    array[size] = newNum;
    size += 1;
    for (int i = size / 2 - 1; i >= 0; i--) 
    {
      maxheapify(array, size, i);
    }
  }
}
void deleteRoot(int array[], int num) //buildmaxheap
{
  int i;
  for (i = 0; i < size; i++) 
  {
    if (num == array[i])
      break;
  }
  swap(&array[i], &array[size - 1]);
  size -= 1;
  for (int i = size / 2 - 1; i >= 0; i--) 
  {
    maxheapify(array, size, i);
  }
}
void printArray(int array[], int size) 
{
  for (int i = 0; i < size; ++i)
    printf("%d ", array[i]);
  printf("\n");
}
int main() 
{
  int array[10];

  insert(array, 3);
  insert(array, 4);
  insert(array, 9);
  insert(array, 5);
  insert(array, 2);

  printf("Max-Heap array: ");
  printArray(array, size);

  deleteRoot(array, 4);

  printf("After deleting an element: ");

  printArray(array, size);
}
    
