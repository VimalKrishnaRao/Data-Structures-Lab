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
            return (Recursebin (a, l, m-1, x));
        return (Recursebin (a, m+1, r, x));
    }
    return -1;
}
int main()
{
    int i, n, x, res, pass, cmp, temp;
    printf ("\nEnter how many elements:");
        scanf ("%d", &n);
    int a[n];
    printf ("\nEnter %d elements to the Array:", n);
    for (i=0; i<n; i++)
        scanf ("%d", &a[i]);
    for (pass=0; pass<n; pass++)
    	for (cmp=0; cmp<n-pass-1; cmp++)
		if (a[cmp]>a[cmp+1])
		{
			temp = a[cmp];
			a[cmp] = a[cmp+1];
			a[cmp+1] = temp;
		}
    printf ("\nEnter the Search element:");
        scanf ("%d", &x);
    res = Recursebin (a, 0, n-1, x);
    if (res==-1)
        printf ("\nSearch element %d not found", x);
    else
        printf ("\nSearch element %d found", x);
    return 1;
}
