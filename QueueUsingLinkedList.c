#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include <stddef.h>

struct Node
{
    int info;
    struct Node *next;
};
typedef struct Node node;
node *prev,*curr,*F,*R= NULL;
node *p;
node *newnode(int val)
{
    p = (node *)malloc(sizeof(node));
    p->info = val;
    p->next = NULL;
    return p;
}
void enqueue_LL(int ele)
{
    p=newnode(ele);
    if(F==NULL)
        F=R=p;
    else
        R->next=p;
    R=p;
}

int dequeue_LL()
{
    int ele = F->info;
    curr=F;
    if(F==R)
    {
        F=R=NULL;
        return ele;
    }
    else
    {
        F=F->next;
    }
    free(curr);
    return (ele);
}
void Display()
{
    curr=F;
    if(F == NULL){
        printf("Queue is Empty\n");
    }
    while (curr->next!=NULL)
    {
        printf("%d\t",curr->info);
        curr=curr->next;
    }
    printf("%d\n",curr->info);
}
int main()
{
    int ch,ele;
    printf("QUEUE USING LINKED LIST");
    do
    {
        printf("\n\nChoose:\n1.Enqueue_LL\n2.Dequeue_LL\n3.Display\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("\nEnter the number to be Inserted : ");
            scanf("%d",&ele);
            enqueue_LL(ele);
            break;
            case 2: if(F == NULL)
                        printf("Queue is Empty\n");
                    else
                    {
                        ele = dequeue_LL();
                        printf("\nDequeued: %d",ele);
                    }
                    break;
            case 3: printf("\nThe Elements in the Queue :\n");
                    Display();
                    break;
            case 4: break;
            default : printf("\nINVALID CHOICE");
        }
    }
    while(ch!=4);
    return 0;
}
