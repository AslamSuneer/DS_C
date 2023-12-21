#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of a linked list
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to merge two linked lists and arrange in ascending order
struct Node* mergeAndSort(struct Node* list1, struct Node* list2) {
    struct Node* mergedList = NULL;

    while (list1 != NULL && list2 != NULL) {
        if (list1->data < list2->data) {
            insertEnd(&mergedList, list1->data);
            list1 = list1->next;
        } else {
            insertEnd(&mergedList, list2->data);
            list2 = list2->next;
        }
    }

    // Add remaining elements from list1
    while (list1 != NULL) {
        insertEnd(&mergedList, list1->data);
        list1 = list1->next;
    }

    // Add remaining elements from list2
    while (list2 != NULL) {
        insertEnd(&mergedList, list2->data);
        list2 = list2->next;
    }

    return mergedList;
}

// Function to display a linked list
void display(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;
    struct Node* mergedList = NULL;

    int n, data;

    // Create the first linked list
    printf("Enter the number of elements for the first list: ");
    scanf("%d", &n);
    printf("Enter elements for the first list:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        insertEnd(&list1, data);
    }

    // Create the second linked list
    printf("Enter the number of elements for the second list: ");
    scanf("%d", &n);
    printf("Enter elements for the second list:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        insertEnd(&list2, data);
    }

    // Merge and arrange the two linked lists in ascending order
    mergedList = mergeAndSort(list1, list2);

    // Display the merged and sorted list
    printf("Merged and Sorted List: ");
    display(mergedList);

    return 0;
}
