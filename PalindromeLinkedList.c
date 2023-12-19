#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for the linked list
struct Node {
    char data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a character into the linked list
void insert(struct Node** head, char data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to reverse a linked list
struct Node* reverse(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

// Function to compare two linked lists
int compareLists(struct Node* list1, struct Node* list2) {
    while (list1 != NULL && list2 != NULL) {
        if (list1->data != list2->data) {
            return 0; // Not a palindrome
        }
        list1 = list1->next;
        list2 = list2->next;
    }

    // If one list is longer than the other
    if (list1 != NULL || list2 != NULL) {
        return 0; // Not a palindrome
    }

    return 1; // Palindrome
}

// Function to display the linked list
void display(struct Node* head) {
    while (head != NULL) {
        printf("%c ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to count the number of nodes in the linked list
int countNodes(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

int main() {
    struct Node* originalList = NULL;
    struct Node* reversedList = NULL;

    char word[50];
    printf("Enter a word: ");
    scanf("%s", word);

    // Insert each character into the linked list
    for (int i = 0; i < strlen(word); i++) {
        insert(&originalList, word[i]);
    }

    // Display original list
    printf("Original List: ");
    display(originalList);

    // Create a reversed list
    reversedList = reverse(originalList);

    // Display reversed list
    printf("Reversed List: ");
    display(reversedList);

    // Compare both lists and check if the word is a palindrome
    if (compareLists(originalList, reversedList)) {
        printf("The word is a palindrome.\n");
    } else {
        printf("The word is not a palindrome.\n");
    }

    // Count the number of nodes in the original list
    printf("Number of nodes in the original list: %d\n", countNodes(originalList));

    return 0;
}
