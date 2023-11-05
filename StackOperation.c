#include <stdio.h>

int main() {
    int A[5]; // Changed the array size to 5
    int top = -1;
    int user = -1; // Initialize user to -1
    int i = 0;

    while (user != 0) {
    st:
        printf("\n MaxSize=5\n");
        printf("\n STACK OPERATIONS\n");
        printf("\n1: PUSH\n");
        printf("\n2: POP\n");
        printf("\n0: EXIT\n"); // Corrected the option number for EXIT
        scanf("%d", &user);

        if (user == 1) {
            i = 0;
            if (top == 4) {
                printf("STACK OVERFLOW\n");
                goto st;
            }
            top = top + 1;
            printf("Enter the element: \n");
            scanf("%d", &A[top]);
            printf("Stack Elements: ");
            while (i <= top) {
                printf("%d\t", A[i]);
                i++;
            }
        } else if (user == 2) {
            i = 0;
            if (top == -1) {
                printf("STACK ALREADY EMPTY\n");
                goto st;
            }
            int v = A[top];
            top = top - 1;
            printf("STACK ELEMENTS: ");
            while (i <= top) {
                printf("%d\t", A[i]);
                i++;
            }
        } else if (user == 0) {
            break;
        } else {
            printf("INVALID INPUT\n");
        }
    }
    return 0;
}
