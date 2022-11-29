#include <stdio.h>
#include <stdlib.h>
struct Queue
{
   int size;
   int front;
   int rear;
   int *Q;
};
void create (struct Queue *q,int size)
{
    q->size=size;
    q->front=q->rear=0;
    q->Q=(int *)malloc(q->size*sizeof(int));
}
void enqueue (struct Queue *q,int x)
{
    if((q->rear+1)%q->size==q->front)
        printf("Queue is Full");
    else
    {
      q->rear=(q->rear+1)%q->size;
      q->Q[q->rear]=x;
    }
}
int dequeue (struct Queue *q)
{
    int x=-1;
    if (q->front==q->rear)
        printf("Queue is Empty\n");
    else
    {
        q->front=(q->front+1)%q->size;
        x=q->Q[q->front];
    }
    return x;
}
void Display(struct Queue q)
{
    int i=q.front+1;
    do
    {
        printf ("%d ",q.Q[i]);
        i=(i+1)%q.size;
    }
    while (i!=(q.rear+1)%q.size);
    printf("\n");
}
int main()
{
      struct Queue q;
      int choice, element;
      create (&q, 5);
      do
      {
        printf("\n-----Menu-----");
        printf("\n1.Enqueue\n2.Dequeue\n3.Display Queue\n4.Exit");
        printf("\nEnter your choice:");
        scanf ("%d",&choice);
        switch(choice)
        {
            case 1: printf("\nEnter the element to be Enqueued:");
                    scanf("%d",&element);
                    enqueue(&q,element);
                    break;
            case 2: printf("\nThe Dequeued Element is %d",dequeue(&q));
                    break;
            case 3: Display(q);
                    break;
            case 4: break;
            default: printf("\nInvalid Choice");
        }
    }
    while(choice!=4);
    return 1;
}
      
