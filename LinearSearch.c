#include<stdio.h>
int Linsearch (int a[], int x, int n)
{
    int i;
    for (i=0; i<n; i++)
        if (a[i]==x)
            return i;
        return -1;
}
int main()
{
    int i, res, n, x, a[50];
    printf ("\nEnter how many elements:");
        scanf ("%d", &n);
    printf ("\nEnter %d Elements to the Array:", n);
    for (i=0; i<n; i++)
        scanf ("%d", &a[i]);
    printf ("\nEnter the Search Element:");
        scanf ("%d", &x);    
    res = Linsearch (a, x, n);
    if (res==-1)
        printf ("\nSearch element %d not found", x);
    else
        printf ("Search element %d is found at %dth Position in the Array", x, res+1);
    return 0;
}
