#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for the binary search tree
struct Node {
    char name[50];
    int mark;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(char name[], int mark) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->name, name);
    newNode->mark = mark;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into the BST
struct Node* insert(struct Node* root, char name[], int mark) {
    if (root == NULL) {
        return createNode(name, mark);
    }

    if (mark > root->mark) {
        root->right = insert(root->right, name, mark);
    } else if (mark < root->mark) {
        root->left = insert(root->left, name, mark);
    }

    return root;
}

// Function to perform an in-order traversal and display records in descending order of marks
void displayDescending(struct Node* root) {
    if (root != NULL) {
        displayDescending(root->right);
        printf("Name: %s, Mark: %d\n", root->name, root->mark);
        displayDescending(root->left);
    }
}

// Function to find the node with the minimum value in a BST
struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;

    // Find the leftmost leaf node
    while (current && current->left != NULL) {
        current = current->left;
    }

    return current;
}

// Function to delete a node from the BST
struct Node* deleteNode(struct Node* root, int mark) {
    if (root == NULL) {
        return root;
    }

    // Recur down the tree
    if (mark < root->mark) {
        root->left = deleteNode(root->left, mark);
    } else if (mark > root->mark) {
        root->right = deleteNode(root->right, mark);
    } else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the inorder successor
        struct Node* temp = minValueNode(root->right);

        // Copy the inorder successor's content to this node
        strcpy(root->name, temp->name);
        root->mark = temp->mark;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->mark);
    }

    return root;
}

// Function to free the memory of the BST
void freeTree(struct Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    struct Node* root = NULL;
    int choice, mark;
    char name[50];

    while (1) {
        printf("\n1. Add Record\n2. Delete Record\n3. Display Records in Descending Order\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter student name: ");
                scanf("%s", name);
                printf("Enter mark: ");
                scanf("%d", &mark);
                root = insert(root, name, mark);
                break;

            case 2:
                printf("Enter mark to delete: ");
                scanf("%d", &mark);
                root = deleteNode(root, mark);
                break;

            case 3:
                printf("\nRecords in Descending Order of Marks:\n");
                displayDescending(root);
                break;

            case 4:
                freeTree(root);
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
