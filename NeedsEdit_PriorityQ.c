#include <stdio.h> 
#include <stdlib.h> 
#define size 10

struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;
}

void create(struct Queue *q, int size); 
void EnQ_priority(struct Queue *q, int element);
void DeQ_priority(struct Queue *q, int element); 
void check_priority(struct Queue q, int element);
void display_priorityqueue(struct Queue q);

void main() 
{ 
    int element, choice; 
    struct Queue q;
    printf("\nEnter 1 to insert element by priority "); 
    printf("\nEnter 2 to delete element by priority "); 
    printf("\nEnter 3 to display priority queue "); 
    printf("\nEnter 4 to exit");  
    create(&q, 10);  
    while (1) 
    { 
        printf("\nEnter your choice : ");    
        scanf("%d", &choice);   
        switch(choice) 
        { 
        case 1: 
            printf("\nEnter element to insert : "); 
            scanf("%d",&element); 
            EnQ_priority(&q, element); 
            break; 
        case 2: 
            printf("\nEnter element to delete : "); 
            scanf("%d",&element); 
            DeQ_priority(&q, element); 
            break; 
        case 3: 
            display_priorityqueue(q); 
            break; 
        case 4: 
            exit(0); 
        default: 
            printf("\n Please enter valid choice"); 
        } 
    } 
}  
void create(struct Queue *q,int size)
{
    q->size=size;
    q->front=q->rear=-1;
    q->Q=(int *)malloc(q->size*sizeof(int));
}  
void EnQ_priority(struct Queue *q, int element) 
{ 
    if (q->rear >= q->size - 1) 
    { 
        printf("\nQUEUE OVERFLOW"); 
        return; 
    } 
    if ((q->front == -1) && (q->rear == -1)) 
    { 
        q->front++; 
        q->rear++; 
        q->Q[q->rear] = element; 
        return; 
    }    
    else 
        check_priority(struct Queue q,element); 
    q->rear++; 
}  
void check_priority(struct Queue q, int element) 
{ 
    int i,j;  
    for (i = 0; i <= q.rear; i++) 
    { 
        if (element >= q.Q[i]) 
        { 
            for (j = q.rear + 1; j > i; j--) 
            { 
                q.Q[j] = q.Q[j - 1]; 
            } 
            q.Q[i] = element; 
            return; 
        } 
    } 
    q.Q[i] = element; 
}  
void DeQ_priority(struct Queue *q, int element)  
{ 
    int i;  
    if ((q->front==-1) && (q->rear==-1)) 
    { 
        printf("\nEmpty Queue"); 
        return; 
    }  
    for (i = 0; i <= q->rear; i++) 
    { 
        if (element == q->Q[i]) 
        { 
            for (; i < q->rear; i++) 
            { 
                q->Q[i] = q->Q[i + 1]; 
            } 
            q->Q[i] = -99; 
            q->rear--; 
            if (q->rear == -1) 
               q->front = -1; 
            return; 
        } 
    } 
    printf("\n%d element not found in queue", element); 
} 
void display_priorityqueue(struct Queue q) 
{ 
    if ((q.front == -1) && (q.rear == -1)) 
    { 
        printf("\nEmpty Queue "); 
        return; 
    }  
    for (; q.front <= q.rear; q.front++) 
    { 
        printf(" %d ", q.Q[q.front]); 
    } 
    q.front = 0; 
}
