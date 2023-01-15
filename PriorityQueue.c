#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 5

struct PriorityQueue 
{
    int A[MAX_SIZE];
    int head;
    int tail;
    int size;
};

void enQ_priority(struct PriorityQueue *q, int x) 
{
    if (q->tail == MAX_SIZE) 
    {
        printf("Queue is full!\n");
        return;
    }
    if (q->head == -1 && q->tail == -1) 
    {
        q->A[0] = x;
        q->head = 0;
        q->tail = 1;
    }
    else
    {
        int i = q->tail-1;
        while (i >= 0 && q->A[i] > x) 
        {
            q->A[i+1] = q->A[i];
            i--;
        }
        q->A[i+1] = x;
        q->tail++;
    }
}

int deQ_priority(struct PriorityQueue *q) 
{
    int x;
    if (q->head < q->tail) 
    {
        x = q->A[q->head];
        q->head++;
        if(q->head==q->tail)
        {
            q->head = -1;
            q->tail = -1;
        }
        return x;
    }
    printf("Queue is empty!\n");
    return -1;
}

void display(struct PriorityQueue *q) 
{
    printf("Elements in the queue: ");
    for (int i = q->head; i < q->tail; i++) 
    {
        printf("%d ", q->A[i]);
    }
    printf("\n");
}

int main() 
{
    struct PriorityQueue q;
    q.head = -1;
    q.tail = -1;
    q.size = MAX_SIZE;

    int choice;
    int input;
    do 
    {
        printf("Menu\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Priority Queue\n");
        printf("4. Exit\n");

        printf("Enter your option: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                printf("Enter a number to enqueue: ");
                scanf("%d", &input);
                enQ_priority(&q, input);
                break;
            case 2:
                input = deQ_priority(&q);
                if (input != -1) 
                {
                    printf("Dequeued: %d\n", input);
                }
                break;
            case 3:
                display(&q);
                break;
            case 4: printf("Exiting...\n");
                    break;
            default: printf("Invalid option!\n");
                     break;
        }
    } 
    while (choice != 4);
    return 0;
}
