#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int coef;
    int expo;
    struct Node *next;
};
typedef struct Node node;
node *poly1, *poly2, *poly3 = NULL;
node *p1, *p2, *p3;
node *newnode()
{
    node *p;
    p = (node *)malloc(sizeof(node));
    p->next = NULL;
    return p;
}
void print(node *a)
{
    node *curr;
    curr = a;
    printf("\nf(x) =");
    while (curr != NULL)
    {
        printf(" %d(x^%d) ",curr->coef,curr->expo);
        curr = curr->next;
        if(curr != NULL)
        {
            printf("+");
        }
    }
}
node *read(node *a)
{
    int ch;
    node *curr, *p;
    printf("\n\nEnter the coefficient & power of polynomial expression in order :-\n");
    do
    {
        p=newnode();
        printf("Enter the coefficient: ");
        scanf("%d",&p->coef);
        printf("Enter the power: ");
        scanf("%d",&p->expo);
        if (a==NULL)
        {
            a=p;
        }
        else
        {
            a->next=p;
        }
        printf("Do you wanna continue(1,0): ");
        scanf("%d",&ch);
    }
    while(ch!=0);
    print(a);
    return(a);
}
void Addpoly()
{
    node *p1, *p2, *p3;
    p1=poly1;
    p2=poly2;
    p3=newnode();
    poly3=p3;
    while (p1!=NULL && p2!=NULL)
    {
        if (p1->expo==p2->expo)
        {
            p3->coef=p1->coef+p2->coef;
            p3->expo=p1->expo;
            p1=p1->next;
            p2=p2->next;
        }
        else
        {
            if(p1->expo > p2->expo)
            {
                p3->expo=p1->expo;
                p3->coef=p1->coef;
                p1=p1->next;
            }
            else
            {
                p3->expo=p2->expo;
                p3->coef=p2->coef;
                p2=p2->next;
            }
        }
        if(p1!=NULL && p2!=NULL)
        {
            p3->next=newnode();
            p3=p3->next;
        }
    }
    while(p1!=NULL)
    {
        p3->next=newnode();
        p3=p3->next;
        p3->expo=p1->expo;
        p3->coef=p1->coef;
        p1=p1->next;
    }
    while(p2!=NULL)
    {
        p3->next=newnode();
        p3=p3->next;
        p3->expo=p2->expo;
        p3->coef=p2->coef;
        p2=p2->next;
    }
}
void main()
{
    poly1=read(poly1);
    poly2=read(poly2);
    Addpoly();
    printf("\n\nThe Sum of poly1 and poly2 is:\n");
    print(poly3);
}
