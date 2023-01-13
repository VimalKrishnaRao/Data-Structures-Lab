#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
    struct Node* next;
    int info;
    struct Node* prev;
}node;
node *head, *curr, *tail=NULL;
node *p;

node *newnode(int ele)
{
    p =(node *)malloc(sizeof(node));
    p->info=ele;
    p->prev=NULL;
    p->next=NULL;
    return(p);
}
void Insert_first(int ele)
{
    p=newnode(ele);
    p->next=head;
    if(head==NULL)
    {
        head=tail=p;
    }
    else
    {
        head->prev=p;
        head=p;
    }
}
void Insert_last(int ele)
{
    p=newnode(ele);
    curr=tail;
    if(head==NULL)
    {
    head=tail=p;
    }
    else
    {
        tail->next=p;
        p->prev=tail;
        tail=p;
    }
}
void Insert_before(int ele, int val)
{
    curr=head;
    while(curr!=NULL && curr->info!=val)
    {
        curr=curr->next;
    }
    if(curr==NULL)
    {
        printf("\nNO SUCH NODE EXISTS");
        return;
    }
    else
    {
        p=newnode(ele);
        p->next=curr;
        p->prev=curr->prev;
        if(curr->prev==NULL)
        {
            head=p;
        }
        else
        {
            curr->prev->next=p;
        }
        curr->prev=p;
    }
}
void Insert_after(int ele, int val)
{
    curr=head;
    while(curr!=NULL && curr->info!=val)
    {
        curr=curr->next;
    }
    if(curr==NULL)
    {
        printf("\nNO SUCH NODE EXISTS");
        return;
    }
    else
    {
        p=newnode(ele);
        p->next=curr->next;
        p->prev=curr;
        if(curr->next==NULL)
        {
            tail=p;
        }
        else
        {
            curr->next->prev=p;
        }
        curr->next=p;
    }
}
void Delete_node(int ele)
{
    curr=head;
    while(curr!=NULL && curr->info!=ele)
    {
        curr=curr->next;
    }
    if(curr==NULL)
    {
        printf("LIST IS EMPTY, DELETION FAILED");
        return;
    }
    else
    {
        if(curr->prev==NULL)
        {
            head=curr->next;
        }
        else
        {
            curr->prev->next=curr->next;
        }
        if(curr->next==NULL)
        {
            tail=curr->prev;
        }
        else
        {
            curr->next->prev=curr->prev;
        }
        free(curr);
    }
}
void display()
{
    printf("Elements in List are: ");
    curr=head;
    while (curr!=NULL)
    {
        printf("%d \t",curr->info);
        curr=curr->next;
    }
}
void main()
{
    int ch,ele,val;
    do
    {
        printf("\n\nChoose:\n1.Insert_First\n2.Insert_Last\n3.Insert_Before\n4.Insert_After\n5.Delete_Node\n6.Display\n7.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter the number to insert: ");
                    scanf("%d",&ele);
                    Insert_first(ele);
                    break;
            case 2: printf("Enter the number to insert: ");
                    scanf("%d",&ele);
                    Insert_last(ele);
                    break;
            case 3: printf("Enter the number to insert: ");
                    scanf("%d",&ele);
                    printf("Enter the number to be considered: ");
                    scanf("%d",&val);
                    Insert_before(ele,val);
                    break;
            case 4: printf("Enter the number to insert: ");
                    scanf("%d",&ele);
                    printf("Enter the number to be considered: ");
                    scanf("%d",&val);
                    Insert_after(ele,val);
                    break;
            case 5: printf("Enter the number to deleted: ");
                    scanf("%d",&ele);
                    Delete_node(ele);
                    break;
            case 6: display();
                    break;
            case 7: break;
            default: printf("INVALID CHOICE");
        }
    }
    while(ch!=7);
}
