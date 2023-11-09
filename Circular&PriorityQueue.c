#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

struct PriorityQueueNode {
    int data;
    int priority;
};

void circularQueueMenu();
void priorityQueueMenu();
void insertCircularQueue(int queue[], int *front, int *rear, int element);
int deleteCircularQueue(int queue[], int *front, int *rear);
void displayCircularQueue(int queue[], int front, int rear);
void insertPriorityQueue(struct PriorityQueueNode queue[], int *rear, int element, int priority);
struct PriorityQueueNode deletePriorityQueue(struct PriorityQueueNode queue[], int *rear);
void displayPriorityQueue(struct PriorityQueueNode queue[], int rear);

int main() {
    int circularQueue[MAX_SIZE], circularFront = -1, circularRear = -1;
    struct PriorityQueueNode priorityQueue[MAX_SIZE];
    int priorityRear = -1, choice;

    do {
        printf("\nMain Menu\n1. Circular Queue\n2. Priority Queue\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: circularQueueMenu(&circularFront, &circularRear); break;
            case 2: priorityQueueMenu(&priorityRear); break;
            case 3: printf("Exiting the program.\n"); break;
            default: printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}

void circularQueueMenu(int *front, int *rear) {
    int circularQueue[MAX_SIZE], choice, element;

    do {
        printf("\nCircular Queue Menu\n1. Insert\n2. Delete\n3. Display\n4. Back to Main Menu\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: printf("Enter the element to insert: "); scanf("%d", &element);
                    insertCircularQueue(circularQueue, front, rear, element); break;
            case 2: element = deleteCircularQueue(circularQueue, front, rear);
                    if (element != -1) printf("Deleted element: %d\n", element); break;
            case 3: displayCircularQueue(circularQueue, *front, *rear); break;
            case 4: printf("Returning to the main menu.\n"); break;
            default: printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);
}

void insertCircularQueue(int queue[], int *front, int *rear, int element) {
    if ((*rear + 1) % MAX_SIZE == *front) { printf("Queue is full. Cannot insert.\n"); return; }
    if (*front == -1) *front = *rear = 0;
    else *rear = (*rear + 1) % MAX_SIZE;
    queue[*rear] = element;
    printf("Element %d inserted successfully.\n", element);
}

int deleteCircularQueue(int queue[], int *front, int *rear) {
    int element;
    if (*front == -1) { printf("Queue is empty. Cannot delete.\n"); return -1; }
    element = queue[*front];
    if (*front == *rear) *front = *rear = -1;
    else *front = (*front + 1) % MAX_SIZE;
    return element;
}

void displayCircularQueue(int queue[], int front, int rear) {
    if (front == -1) { printf("Queue is empty.\n"); return; }
    printf("Circular Queue: ");
    int i = front;
    do { printf("%d ", queue[i]); i = (i + 1) % MAX_SIZE; } while (i != (rear + 1) % MAX_SIZE);
    printf("\n");
}

void priorityQueueMenu(int *rear) {
    struct PriorityQueueNode priorityQueue[MAX_SIZE];
    int choice, element, priority;

    do {
        printf("\nPriority Queue Menu\n1. Insert\n2. Delete\n3. Display\n4. Back to Main Menu\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: printf("Enter the element to insert: "); scanf("%d", &element);
                    printf("Enter the priority of the element: "); scanf("%d", &priority);
                    insertPriorityQueue(priorityQueue, rear, element, priority); break;
            case 2: struct PriorityQueueNode deletedNode = deletePriorityQueue(priorityQueue, rear);
                    if (deletedNode.data != -1) printf("Deleted element: %d with priority %d\n", deletedNode.data, deletedNode.priority); break;
            case 3: displayPriorityQueue(priorityQueue, *rear); break;
            case 4: printf("Returning to the main menu.\n"); break;
            default: printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 4);
}

void insertPriorityQueue(struct PriorityQueueNode queue[], int *rear, int element, int priority) {
    if (*rear == MAX_SIZE - 1) { printf("Queue is full. Cannot insert.\n"); return; }
    *rear = *rear + 1;
    queue[*rear].data = element;
    queue[*rear].priority = priority;
    printf("Element %d with priority %d inserted successfully.\n", element, priority);
}

struct PriorityQueueNode deletePriorityQueue(struct PriorityQueueNode queue[], int *rear) {
    struct PriorityQueueNode deletedNode = { -1, -1 };
    if (*rear == -1) { printf("Queue is empty. Cannot delete.\n"); return deletedNode; }
    int highestPriorityIndex = 0;

    for (int i = 1; i <= *rear; i++)
        if (queue[i].priority < queue[highestPriorityIndex].priority)
            highestPriorityIndex = i;

    deletedNode = queue[highestPriorityIndex];

    for (int i = highestPriorityIndex; i < *rear; i++)
        queue[i] = queue[i + 1];

    *rear = *rear - 1;

    return deletedNode;
}

void displayPriorityQueue(struct PriorityQueueNode queue[], int rear) {
    if (rear == -1) { printf("Queue is empty.\n"); return; }
    printf("Priority Queue: ");
    for (int i = 0; i <= rear; i++) printf("(%d, %d) ", queue[i].data, queue[i].priority);
    printf("\n");
}
