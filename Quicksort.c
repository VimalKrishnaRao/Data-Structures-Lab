#include<stdio.h>
int partition (int a[], int p, int r)
{
        int t, q;
        t=a[p];
        q=p;
        for (int i=p+1;i<=r;i++)
                if (a[i]<t)
                {
                        a[q++]=a[i];
                        a[i]=a[q];
                }
                a[q]=t;
                return q;
}
void qs(int a[], int p, int r)
{
        int q;
        if (p<r)
        {
                q=partition (a,p,r);
                qs (a,p,q-1);
                qs (a,q+1,r);
        }
}
int main()
{
   int i, count, number[25];
   printf ("Enter the number of elements: ");
   scanf ("%d",&count);
   printf ("Enter %d elements: ", count);
   for (i=0;i<count;i++)
        scanf ("%d",&number[i]);
   qs (number,0,count-1);
   printf("Order of Sorted elements: ");
   for(i=0;i<count;i++)
        printf (" %d",number[i]);
   return 0;
}      
