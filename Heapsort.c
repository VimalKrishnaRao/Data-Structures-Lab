#include <stdio.h>
void swap(int a[], int i, int j) 
{
  int temp = a[i];
  a[i] = a[j];
  a[j] = temp;
}
void maxheapify (int array[], int n, int k) 
{
    int max;
    int l = 2 * k;
    int r = 2 * k + 1;
    if (l <= n && array[l] > array[k])
        max = l;
    else 
        max = k;
    if (r <= n && array[r] > array[max])
      max = r;
    if (max!= k) 
    {
      swap(array, k, max);
      maxheapify(array, n, max);
    }
}
void buildmaxheap (int array[], int n)
{
        int i;
        for (i=n/2;i>0;i--)
                maxheapify (array, n, i);
}
void Heapsort (int array[], int n)
{
        int i;
        buildmaxheap (array, n);
        for (i=1;i<n;i++)
        {
                swap (array, 1, n-i+1);
                maxheapify (array, n-i, 1);
        }
}
int main() 
{
  int x,n;
  int i;
  printf ("\nEnter how many numbers:");
  scanf ("%d",&n);
  int array[n];
  printf ("\nEnter %d Elements:",n);
  for (i=0;i<n;i++)
        scanf ("%d", &array[i]);
  Heapsort (array, n);
  printf ("Heap Sorted Array is: ");
  for (i=0;i<n;i++)
        printf ("%d ", array[i]);
  return 1;
}
  
