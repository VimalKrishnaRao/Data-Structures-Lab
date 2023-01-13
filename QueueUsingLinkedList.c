#include<stdio.h>
#include<stdlib.h>
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
void Insert_rear(int ele)
{
    p=newnode(ele);
    if(F==NULL)
        F=R=p;
    else
        R->next=p;
    R=p;
}
void Insert_front(int ele)
{
    p=newnode(ele);
    if(F==NULL)
        F=R=p;
    else
    {
        p->next=F;
        F=p;
    }
}
int Delete_rear()
{
    int ele = R->info;
    curr=F;
    if(F==R)
        F=R=NULL;
    else
    {
        while (curr->next!=NULL)
        {
            prev=curr;
            curr=curr->next;
        }
        R=prev;
        prev->next=NULL;
    }
    free(curr);
    return (ele);
}
int Delete_front()
{
    int ele = F->info;
    curr=F;
    if(F==R)
        F=R=NULL;
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
    while (curr->next!=NULL)
    {
        printf("%d\t",curr->info);
        curr=curr->next;
    }
    printf("%d\n",curr->info);
}
void main()
{
    int ch,ele;
    printf("QUEUE USING LINKED LIST");
    do
    {
        printf("\n\nChoose:\n1.Insert_Front\n2.Insert_Rear\n3.Delete_Front\n4.Delete_Rear\n5.Display\n6.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("\nEnter the number to be Inserted : ");
                    scanf("%d",&ele);
                    Insert_front(ele);
                    break;
            case 2: printf("\nEnter the number to be Inserted : ");
                    scanf("%d",&ele);
                    Insert_rear(ele);
                    break;
            case 3: ele = Delete_front();
                    printf("\nThe Deleted value is %d",ele);
                    break;
            case 4: ele = Delete_rear();
                    printf("\nThe Deleted value is %d",ele);
                    break;
            case 5: printf("\nThe Elements in the Stack :\n");
                    Display();
                    break;
            case 6: break;
            default : printf("\nINVALID");
        }
    }
    while(ch!=6);
}
