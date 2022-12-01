#include<stdio.h>
void swap(int a[], int i, int j)
{
    int temp;
    temp=a[i];
    a[i]=a[j];
    a[j]=temp;
}
void selectionsort(int a[], int n)
{
    int i, j, min_idx;
    for (i=0;i<n-1;i++)
    {
        min_idx=i;
        for (j=i+1;j<n;j++)
            if (a[j]<a[min_idx])
                min_idx=j;
        swap(a,i,min_idx);
    }
}
void printarray(int a[], int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
}
int main()
{
    int a[100],n,i,size;
    printf("Enter how many elements:");
    scanf("%d",&n);
    printf("\nEnter %d Elements:",n);
    for (i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("\nThe Sorted array is:\n");
    selectionsort(a,n);
    printarray(a,n);
    return 0;
}
