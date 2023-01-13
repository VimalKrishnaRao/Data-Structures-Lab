#include<stdio.h>
#define size 5
int F =-1, R =-1, Q[size];
int is_full()
{
    if(F==(R+1)%size)
        return(1);
    else
        return(0);
}
int is_empty()
{
    if(F==-1 && R==-1)
        return(1);
    else
        return(0);
}
void Insert_Rear(int ele)
{
    R=(R+1)%size;
    if(F==-1)
        F=0;
    Q[R] = ele;
}
void Insert_Front(int ele)
{
    if(F==-1)
        F=R=0;
    else
    {
        if(F==0)
            F=size-1;
        else
            F=F-1;
    }
    Q[F] = ele;
}
int Delete_Rear()
{
    int ele = Q[R];
    if(F==R)
        F=R=-1;
    else
    {
        if(R==0)
            R=size-1;
        else
            R=R-1;
        return (ele);
    }
}
int Delete_Front()
{
    int ele = Q[F];
    if(F==R)
            F=R=-1;
        else
            F=(F+1)%size;
    return (ele);
}
void Display()
{
    if(is_empty())
        printf("QUEUE EMPTY");
    else
    {
        int i;
        for(i=F;i!=R;i=(i+1)%size)
            printf("%d \n",Q[i]);
        printf("%d \n",Q[R]);
    }
}
void main()
{
    int cho,ch,ele;
    printf("DOUBLE ENDED QUEUE");
    do
    {
        printf("\n\nChoose:\n1.Insert_Rear\n2.Insert_Front\n3.Delete_Rear\n4.Delete_Front\n5.IsFull\n6.IsEmpty\n7.Display\n8.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: if (is_full())
                        printf("QUEUE FULL");
                    else
                    {
                        printf("\nEnter the number to be inserted:");
                        scanf("%d",&ele);
                        Insert_Rear(ele);
                    }
                    break;
            case 2: if (is_full())
                        printf("QUEUE FULL");
                    else
                    {
                        printf("\nEnter the number to be inserted:");
                        scanf("%d",&ele);
                        Insert_Front (ele);
                    }
                    break;
            case 3: if (is_empty())
                        printf("QUEUE IS EMPTY");
                    else
                    {
                        ele=Delete_Rear();
                        printf("The Deleted element is %d",ele);
                    }
                    break;
            case 4: if (is_empty())
                        printf("QUEUE IS EMPTY");
                    else
                    {
                        ele=Delete_Front();
                        printf("The Deleted element is %d",ele);
                    }
                    break;
            case 5: if (is_full())
                        printf("QUEUE FULL");
                    else
                        printf("SPACE AVAILABLE");
                    break;
            case 6: if (is_empty())
                        printf("QUEUE IS EMPTY");
                    else
                        printf("MEMBERS OCCUPIED");
                    break;
            case 7: printf("\nThe Elements in the Queue are:\n");
                    Display();
                    break;
            case 8: break;
            default : printf("\nINVALID CHOICE");
        }
    }
    while(ch!=8);
}
