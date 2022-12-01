#include<stdio.h>
void insertionsort(int a[], int n)
{
    int i,j,x;
    for (i=1;i<=n;i++)   //Comparisons
    {
        x=a[i];
        for (j=i-1;j>=0;j--)    //Iterations
            if (x<a[j])
                a[j+1]=a[j];
            else
                break;
        a[j+1]=x;
    }
}
void printarray(int a[], int n)
{
    int i;
    for (i=0;i<n;i++)
        printf("%d\t",a[i]);
}
int main()
{
    int a[50],i,n;
    printf("\nEnter how many elements:");
    scanf("%d",&n);
    printf("\nEnter %d numbers:",n);
    for (i=0;i<n;i++)
        scanf("%d",&a[i]);
    insertionsort(a,n);
    printf("\nThe Sorted array is:\n");
        printarray(a,n);
    return 0;
}
