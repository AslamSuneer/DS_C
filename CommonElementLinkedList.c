#include <stdio.h>
#include <stdlib.h>

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

// Function to insert a node at the end of the linked list
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

// Function to display the linked list
void display(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to find common elements and create a new linked list
struct Node* findCommon(struct Node* list1, struct Node* list2) {
    struct Node* commonList = NULL;

    while (list1 != NULL) {
        struct Node* temp = list2;
        while (temp != NULL) {
            if (list1->data == temp->data) {
                insertEnd(&commonList, list1->data);
                break;
            }
            temp = temp->next;
        }
        list1 = list1->next;
    }

    return commonList;
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;
    struct Node* commonList = NULL;

    int n1, n2, data;

    // Input for the first list
    printf("Enter the number of elements for the first list: ");
    scanf("%d", &n1);
    printf("Enter the elements for the first list:\n");
    for (int i = 0; i < n1; i++) {
        scanf("%d", &data);
        insertEnd(&list1, data);
    }

    // Input for the second list
    printf("Enter the number of elements for the second list: ");
    scanf("%d", &n2);
    printf("Enter the elements for the second list:\n");
    for (int i = 0; i < n2; i++) {
        scanf("%d", &data);
        insertEnd(&list2, data);
    }

    // Display the input lists
    printf("First List: ");
    display(list1);
    printf("Second List: ");
    display(list2);

    // Find common elements and create a new list
    commonList = findCommon(list1, list2);

    // Display the common list
    printf("Common List: ");
    display(commonList);

    return 0;
}
