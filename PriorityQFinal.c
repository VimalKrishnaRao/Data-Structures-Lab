#include<stdio.h>
#define max 5
int PQ[max+1], curr=0, par=0, hsize=0;
void swap(int PQ[],int a,int b)
{
    int temp=PQ[a];
    PQ[a]=PQ[b];
    PQ[b]=temp;
}
void heapify(int i, int s, int a[])
{
    int lc=2*i;
    int rc=(2*i)+1;
    int lar = i;
    if(lc<=s && a[lc]<a[lar])
    {
        lar=lc;
    }
    if(rc<=s && a[rc]<a[lar])
    {
        lar=rc;
    }
    if(lar!=i)
    {
        int tmp=a[i];
        a[i]=a[lar];
        a[lar]=tmp;
        heapify(lar,s,a);
    }
}
int is_full()
{
    if(hsize==max)
        return(1);
    else
        return(0);
}
int is_empty()
{
    if(hsize==0)
        return(1);
    else
        return(0);
}
void Insert(int ele)
{
    hsize++;
    PQ[hsize]=ele;
    curr=hsize;
    par=curr/2;
    while(par>=1 && PQ[par]>PQ[curr])
    {
        swap(PQ,curr,par);
        curr=par;
        par=curr/2;
    }
}
int Delete()
{
    int ele = PQ[1];
    swap(PQ,1,hsize);
    hsize--;
    heapify(1,hsize,PQ);
    return (ele);
}
void Display()
{
    if(is_empty())
        printf("QUEUE EMPTY");
    else
    {
        int i;
        for(i=1;i<=hsize;i++)
            printf("%d \n",PQ[i]);
    }
}
void main()
{
    int ch,ele;
    printf("PRIORITY QUEUE");
    do
    {
        printf("\n\nChoose:\n1.Insert\n2.Delete\n3.IsFull\n4.IsEmpty\n5.Display\n6.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: if(is_full())
                        printf("QUEUE FULL");
                    else
                    {
                        printf("\nEnter the number to be inserted:");
                        scanf("%d",&ele);
                        Insert(ele);
                    }
                    break;
            case 2: if(is_empty())
                        printf("QUEUE IS EMPTY");
                    else
                    {
                        ele=Delete();
                        printf("The deleted element is %d",ele);
                    }
                    break;
            case 3: if(is_full())
                        printf("QUEUE FULL");
                    else
                        printf("SPACE AVAILABLE");
                    break;
            case 4: if(is_empty())
                        printf("QUEUE IS EMPTY");
                    else
                        printf("MEMBERS OCCUPIED");
                    break;
            case 5: printf("\nThe elements in the Queue are:\n");
                    Display();
                    break;
            case 6: break;
            default: printf("\nINVALID CHOICE");
        }
    }
    while(ch!=6);
}
