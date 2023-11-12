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
