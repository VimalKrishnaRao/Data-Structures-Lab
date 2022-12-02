#include<stdio.h>
int Recursebin (int a[], int l, int r, int x)
{
    int m;
    if (l<=r)
    {
        m=(l+r)/2;
        if (a[m]==x)
            return m;
        if (x<a[m])
            Recursebin (a, l, m-1, x);
        Recursebin (a, m+1, r, x);
    }
    return -1;
}
int main()
{
    int i, a[50], n, x, res;
    printf ("\nEnter how many elements:");
        scanf ("%d", &n);
    printf ("\nEnter %d elements to the Array:", n);
    for (i=0; i<n; i++)
        scanf ("%d", &a[i]);
    printf ("\nEnter the Search element:");
        scanf ("%d", &x);
    res = Recursebin (a, 0, n-1, x);
    if (res==-1)
        printf ("\nSearch element %d not found", x);
    else
        printf ("\nSearch element %d is found at %dth Position in the Array", x, res+1);
    return 1;
}
