#include<stdio.h>
void swap (int a[], int i, int j)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}
int Recursebin (int a[], int l, int r, int x)
{
    int m;
    if (l<=r)
    {
        m=(l+r)/2;
        if (a[m]==x)
            return m;
        if (x<a[m])
            return(Recursebin (a, l, m-1, x));
        return(Recursebin (a, m+1, r, x));
    }
    return -1;
}
int main()
{
    int i, a[50], n, x, res, pass, cmp;
    printf ("\nEnter how many elements:");
        scanf ("%d", &n);
    printf ("\nEnter %d elements to the Array:", n);
    for (i=0; i<n; i++)
        scanf ("%d", &a[i]);
    printf ("\nEnter the Search element:");
        scanf ("%d", &x);
    for (pass=0; pass<n; pass++)
        for (cmp=1; cmp<n-pass; cmp++)
            swap (a, cmp, cmp+1);
    res = Recursebin (a, 0, n-1, x);
    if (res==-1)
        printf ("\nSearch element %d not found", x);
    else
        printf ("\nSearch element %d is found at %dth Position in the Array", x, res+1);
    return 1;
}
