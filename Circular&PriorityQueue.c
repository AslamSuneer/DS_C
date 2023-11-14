
#include <stdio.h>
struct PQ {
    int itempq, priority;
};
int size, front, rear;
int frontpq, rearpq;
struct PQ A[20];

void ENQUEUE_CQ(int item) {
    if ((rear + 1) % size == front)
        printf("Queue is FULL\n");
    else if (rear == -1) {
        front = 0;
        rear = 0;
        A[rear].itempq =item;
       A[rear].priority =0;
    } else {
        rear = (rear + 1) % size;
         A[rear].itempq =item;
       A[rear].priority =0;
    }
}

int frontpq, rearpq;

void enqueuepq(int ITEM_PQ, int PRIORITY) {
    int i, loc;
    if (frontpq == 0 && rearpq == size - 1)
        printf("Queue is FULL\n");
    else if (frontpq == -1) {
        frontpq = 0;
        rearpq = 0;
        A[rearpq].itempq = ITEM_PQ;
        A[rearpq].priority = PRIORITY;
    } else {
        if (rearpq == size - 1) {
            for (i = frontpq; i <= rearpq; i++)
                A[i - 1] = A[i];
            frontpq--;
            rearpq--;
        }
        for (i = rearpq; i >= frontpq; i--) {
            if (A[i].priority < PRIORITY) {
                break;
            }
        }
        loc = i + 1;
        for (i = rearpq; i >= loc; i--) {
            A[i + 1] = A[i];
        }
        A[loc].itempq = ITEM_PQ;
        A[loc].priority = PRIORITY;
        rearpq++;
    }
}

void DEQUEUE_CQ() {
    if (front == -1)
        printf("Queue is EMPTY\n");
    else if (front == rear) {
        printf("Deleted item is %d", A[front]);
        front = -1;
        rear = -1;
    } else {
        printf("Deleted item is %d", A[front]);
        front = (front + 1) % size;
    }
}

void dequeuepq() {
    if (frontpq == -1)
        printf("Queue is empty\n");
    else if (frontpq == rearpq) {
        printf("Deleted item is %d\n", A[frontpq].itempq);
        frontpq = -1;
        rearpq = -1;
    } else {
        printf("Deleted item is %d\n", A[frontpq].itempq);
        frontpq++;
    }
}

void DISPLAY_CQ() {
    int i;
    if (front == -1)
        printf("Queue is EMPTY");
    else if (front <= rear) {
        for (i = front; i <= rear; i++)
            printf("%d\t", A[i]);
    } else {
        for (i = front; i <= (size - 1); i++)
            printf("%d\t", A[i]);
        for (i = 0; i <= rear; i++)
            printf("%d\t", A[i]);
    }
    printf("\n");
}

void displaypq() {
    int i;
    if (frontpq == -1)
        printf("Queue is EMPTY\n");
    else {
        for (i = frontpq; i <= rearpq; i++)
            printf("%d\t", A[i].itempq);
        printf("\n");
    }
}

int main() {
    int item, opt, itempq, prio;
    frontpq = -1;
    rearpq = -1;
    front = -1;
    rear = -1;

    printf("Enter the size of the Queue: ");
    scanf("%d", &size);

    do {
        printf("1.ENQUEUECQ\n2.DEQUEUECQ\n3.DISPLAYCQ\n4.EnqueuePQ\n5.DequeuePQ\n6.DisplayPQ\n7.EXIT\n");
        printf("\nEnter the option:");
        scanf("%d", &opt);

        switch (opt) {
        case 1:
            printf("Enter element to insert: ");
            scanf("%d", &item);
            ENQUEUE_CQ(item);
            break;
        case 2:
            DEQUEUE_CQ();
            break;
        case 3:
            DISPLAY_CQ();
            break;
        case 4:
            printf("Enter the item and priority: ");
            scanf("%d %d", &itempq, &prio);
            enqueuepq(itempq, prio);
            break;
        case 5:
            dequeuepq();
            break;
        case 6:
            displaypq();
            break;
        case 7:
            break;
        default:
            printf("Enter a valid option\n");
        }
    } while (opt != 7);

    return 0;
}
