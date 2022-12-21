#include<stdio.h>
#define size 50
int stack[size], top=0, choice, element;
    int isfull()
    {
        if (top==size)
            return 1;
        else
            return 0;
    }
    int isempty()
    {
        if (top==0)
            return 1;
        else
            return 0;
    }    
    void push(int element)
    {
        if (isfull())
            printf("\nStack is full, cannot push values");
        else
            stack[top++]=element;
    }
    int pop()
    {
        if (isempty())
            return -1;
        else
        {
            top=top-1;
            return (stack[top]);
        }
    }
    int peek()
    {
        if (isempty())
        {
            printf("\nStack is Empty, Peek Failed");
            return 0;
        }
        else
            return (stack[top-1]);
    }
    
    int displayStack()
    {
        int i;
        for (i=top-1; i>=0; i--)
            printf("\n%d",stack[i]);
    }
void main()
{
    int a=0,b,c,choice;
    do
    {
        printf("\n--------Menu--------");
        printf("\n1.Push\n2.Pop\n3.Peek\n4.IsFull\n5.IsEmpty\n6.Display Stack\n7.Exit");
        printf("\nEnter your Choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("\nEnter the element to be pushed:");
                        scanf("%d",&element);
                        push(element);
                    break;
            case 2: element=pop();
                        if(element==-1)
                            printf ("Stack is Empty, Cannot Pop Values");
                        else
                            printf("\nPopped Element is %d",x);
                    break;
            case 3: a=peek();
                    if(a!=0)
                        printf("The Element at the top is %d",a);
                    break;
            case 4: b=isfull();
                    if (b==1)
                        printf("\nStack is Full");
                    else
                        printf("\nStack is Not Full");
                    break;
            case 5: c=isempty();
                    if (c==1)
                                printf("\nStack is Empty");
                        else
                                printf("\nStack is Not Empty");
                    break;
            case 6: displayStack();
                    break;
            case 7: break;
            default: printf("\nInvalid Choice");
        }
    }
    while (choice!=7);
 }
