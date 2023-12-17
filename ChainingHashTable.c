 #include <stdio.h>
#include <stdlib.h>
#define SIZE 10

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insert(struct Node* hashTable[], int key) {
    int index = key%SIZE;
    struct Node* newNode = createNode(key);

   
    if (hashTable[index] == NULL) {
        hashTable[index] = newNode;
    }
   
    else {
        struct Node* temp = hashTable[index];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}


void display(struct Node* hashTable[]) {
    for (int i = 0; i < SIZE; i++) {
        printf("Index %d: ", i);
        struct Node* temp = hashTable[i];
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
       
    }
}

int main() {
    struct Node* hashTable[SIZE] = {NULL};

   
    int n;
    printf("Enter the number of elements to insert: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        int key;
        scanf("%d", &key);
        insert(hashTable, key);
    }

    printf("\nHash Table:\n");
    display(hashTable);

    return 0;
}
