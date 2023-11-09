#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* queueFront = NULL;
struct Node* queueRear = NULL;
struct Node* stackTop = NULL;

int isStackEmpty() {
    return stackTop == NULL;
}

int isQueueEmpty() {
    return queueFront == NULL;
}

void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = stackTop;
    stackTop = newNode;
    printf("%d pushed into stack\n", value);
}

void enqueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if (queueFront == NULL) {
        queueFront = newNode;
    }
    else {
        queueRear->next = newNode;
    }
    queueRear = newNode;
    printf("%d enqueued\n", value);
}

void pop() {
    if (isStackEmpty()) {
        printf("Stack is empty\n");
        return;
    }
    struct Node* temp = stackTop;
    stackTop = stackTop->next;
    printf("%d popped from stack\n", temp->data);
    free(temp);
}

void dequeue() {
    if (isQueueEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    struct Node* temp = queueFront;
    queueFront = queueFront->next;
    printf("%d dequeued\n", temp->data);
    free(temp);
}

void displayStack() {
    struct Node* current = stackTop;
    printf("Stack elements: \n");
    while (current != NULL) {
        printf("%d\t", current->data);
        current = current->next;
    }
    printf("\n");
}

void displayQueue() {
    struct Node* current = queueFront;
    printf("Queue elements: \n");
    while (current != NULL) {
        printf("%d\t", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    int choice;
    int element;
    while (1) {
        printf("1. Push\n2. Pop\n3. Display Stack\n4. Enqueue\n5. Dequeue\n6. Display Queue\n7. Exit\n");
        printf("Enter the choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter element to push: ");
            scanf("%d", &element);
            push(element);
            break;
        case 2:
            pop();
            break;
        case 3:
            displayStack();
            break;
        case 4:
            printf("Enter element to enqueue: ");
            scanf("%d", &element);
            enqueue(element);
            break;
        case 5:
            dequeue();
            break;
        case 6:
            displayQueue();
            break;
        case 7:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}
