#include<stdio.h>
void swap (int a[], int i, int j)
{
    int temp;
    temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}
void bubblesort (int a[], int n)
{
    int i, j;
    for (i=0; i<n; i++)
        for (j=0; j<n-i-1; j++)
            if (a[j]>a[j+1])
                swap (a, j, j+1);
}
void main()
{
    int n, i;
    printf ("\nEnter how many numbers:");
        scanf ("%d", &n);
    int a[n];
    printf ("\nEnter %d Elements in the Array:", n);
        for (i=0; i<n; i++)
            scanf ("%d", &a[i]);
    bubblesort (a, n);
    printf ("\nThe Bubble Sorted Array is:");
        for (i=0; i<n; i++)
            printf ("%d\t", a[i]);
}
