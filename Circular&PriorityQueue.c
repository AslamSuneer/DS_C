#include<stdio.h>
int A[20],size,front,rear;
void ENQUEUE_CQ(int item){
if((rear+1)%size==front)
printf("Queue is FULL\n");
else if(rear==-1)
{
front=0;
rear=0;
A[rear]=item;
}
else
{
rear=(rear+1)%size;
A[rear]=item;
}
}
void DEQUEUE_CQ()
{
if(front==-1)
printf("Queue is EMPTY");
else if(front==rear)
{
printf("Deleted item is %d", A[front]); 
front=-1; rear=-1;
}
else
{
printf("Deleted item is %d",A[front]); 
    front=(front+1)%size;
}
}
void DISPLAY_CQ()
{ 
    int i;
if(front==-1)
printf("Queue is EMPTY");
else if(front<=rear)
{ 
    for(i=front;i<=rear;i++) 
    printf("%d\t", A[i]);
}
else
{
    for(i=front;i<=(size-1);i++) printf("%d\t",A[i]); 
    for(i=0;i<=rear;i++)
    printf("%d\t", A[i]);
}
printf("\n");
} 
void main()
{
int item,opt;
front=-1;
rear=-1;
printf("Enter the size of the Queue: "); 
scanf("%d", &size);
do
{
printf("1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\n4.EXIT\n"); 
printf("\nEnter the option:");
scanf("%d",&opt);
switch(opt)
{
 case 1: printf("Enter element to insert: "); 
scanf("%d",&item);
ENQUEUE_CQ(item); break;
case 2: DEQUEUE_CQ(); break;
case 3: DISPLAY_CQ();break;
case 4: break;
default: printf("Invalid option"); 
}
}while(opt!=4);
}



#include <stdio.h>

int size, front, rear;

struct PQ
{
    int item, priority;
} A[20];

void display()
{
    int i;
    if (front == -1)
        printf("Queue is EMPTY\n");
    else
    {
        for (i = front; i <= rear; i++)
            printf("%d\t", A[i].item);
        printf("\n");
    }
}

void enqueue(int ITEM, int PRIORITY)
{
    int i, loc;
    if (front == 0 && rear == size - 1)
        printf("Queue is FULL\n");
    else if (front == -1)
    {
        front = 0;
        rear = 0;
        A[rear].item = ITEM;
        A[rear].priority = PRIORITY;
    }
    else
    {
        if (rear == size - 1)
        {
            for (i = front; i <= rear; i++)
                A[i - 1] = A[i];
            front--;
            rear--;
        }
        for (i = rear; i >= front; i--)
        {
            if (A[i].priority < PRIORITY)
            {
                break;
            }
        }
        loc = i + 1;
        for (i = rear; i >= loc; i--)
        {
            A[i + 1] = A[i];
        }
        A[loc].item = ITEM;
        A[loc].priority = PRIORITY;
        rear++;
    }
}

void dequeue()
{
    if (front == -1)
        printf("Queue is empty\n");
    else if (front == rear)
    {
        printf("Deleted item is %d\n", A[front].item);
        front = -1;
        rear = -1;
    }
    else
    {
        printf("Deleted item is %d\n", A[front].item);
        front++;
    }
}

int main()
{
    int opt, item, prio;
    front = -1;
    rear = -1;
    printf("Enter the size of the queue: ");
    scanf("%d", &size);
    do
    {
        printf("\nEnter the option\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            printf("Enter the item and priority: ");
            scanf("%d %d", &item, &prio);
            enqueue(item, prio);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            break;
        default:
            printf("Enter a valid option\n");
        }

    } while (opt != 4);

    return 0;
}
