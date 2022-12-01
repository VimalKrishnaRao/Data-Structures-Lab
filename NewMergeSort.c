#include<stdio.h>
void Merge(int A[],int l,int mid,int h)
{
    int i=l,j=mid+1,k=l;
    int B[100];
    while (i<=mid && j<=h)
    {
        if (A[i]<A[j])
            B[k++]=A[i++];
        else
            B[k++]=A[j++];
    }
    for (;i<=mid;i++)
        B[k++]=A[i];
    for (;j<=h;j++)
        B[k++]=A[j];
    for(i=l;i<=h;i++)
        A[i]=B[i];
}
void MergeSort(int A[],int l,int h)
{
    int mid;
    if (l<h)
    {
        mid=(l+h)/2;
        MergeSort(A,l,mid);
        MergeSort(A,mid+1,h);
        Merge(A,l,mid,h);
    }
}
int main()
{
    int n,i;
    printf ("\nEnter the number of array elements to be inputed:");
        scanf ("%d",&n);
    int A[n];
    printf ("\nEnter %d Elements:",n);
    for (i=0;i<n;i++)
        scanf ("%d",&A[i]);
    MergeSort(A,0,n);
    printf ("The Array sorted using Merge Sort is:");
    for (i=0;i<n;i++)
        printf("%d ",A[i]);
    printf("\n");
    return 0;
}
