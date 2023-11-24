#include <stdio.h>
#include <stdlib.h>

struct poly {
    int coef;
    int exp;
    struct poly* link;
};

void insert(struct poly** head, int coef, int exp) {
    struct poly* temp = (struct poly*)malloc(sizeof(struct poly));
    struct poly* ptr = (*head);
    temp->coef = coef;
    temp->exp = exp;
    temp->link = NULL;

    if (ptr == NULL || exp < ptr->exp) {
        temp->link = ptr;
        (*head) = temp;
    }
    else {
        while (ptr->link != NULL && exp > ptr->link->exp) {
            ptr = ptr->link;
        }
        temp->link = ptr->link;
        ptr->link = temp;
    }
}

void new_poly(struct poly** head) {
    int n, i, coef, exp;
    printf("Enter number of Terms in the polynomial: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        printf("Enter coefficient for term (%d): ", i);
        scanf("%d", &coef);
        printf("Enter exponent for term(%d): ", i);
        scanf("%d", &exp);
        insert(&(*head), coef, exp);
    }
}

void display(struct poly** head) {
    struct poly* ptr = (*head);
    if (ptr == NULL) {
        printf("Empty List ");
    }
    else {
        while (ptr != NULL) {
            printf("%dx^", ptr->coef);
            printf("%d ", ptr->exp);
            if (ptr->link != NULL) {
                printf("+");
            }
            ptr = ptr->link;
        }
        printf("\n");
    }
}

void multiply(struct poly** poly1, struct poly** poly2, struct poly** result) {
    struct poly* ptr1 = (*poly1);
    struct poly* ptr2 = (*poly2);

    while (ptr1 != NULL) {
        struct poly* tempResult = NULL;
        while (ptr2 != NULL) {
            int coef = ptr1->coef * ptr2->coef;
            int exp = ptr1->exp + ptr2->exp;
            insert(&tempResult, coef, exp);
            ptr2 = ptr2->link;
        }
        ptr2 = (*poly2);
        ptr1 = ptr1->link;

        // Add the current temporary result to the final result
        while (tempResult != NULL) {
            struct poly* existingTerm = *result;
            while (existingTerm != NULL && existingTerm->exp != tempResult->exp) {
                existingTerm = existingTerm->link;
            }
            if (existingTerm != NULL) {
                // Matching exponent found
                if (existingTerm->coef * tempResult->coef < 0) {
                    // Cancel out terms with opposite signs
                    existingTerm->coef += tempResult->coef;
                    if (existingTerm->coef == 0) {
                        // Remove canceled term
                        if (existingTerm->link != NULL) {
                            existingTerm->link = existingTerm->link->link;
                        } else {
                            *result = NULL;
                        }
                        free(tempResult);
                    }
                } else {
                    // Add terms with the same sign
                    existingTerm->coef += tempResult->coef;
                    free(tempResult);
                }
            } else {
                // No matching exponent found, add the term to the result
                insert(result, tempResult->coef, tempResult->exp);
                struct poly* temp = tempResult;
                tempResult = tempResult->link;
                free(temp);
            }
        }
    }
}


int main() {
    struct poly* poly1 = NULL, * poly2 = NULL, * poly3 = NULL;
    int n, m;
    printf("First Polynomial \n");
    new_poly(&poly1);
    printf("Polynomial 1 = ");
    display(&poly1);
printf("Second Polynomial \n");
    new_poly(&poly2);
    printf("Polynomial 2 = ");
    display(&poly2);

    multiply(&poly1, &poly2, &poly3);
    printf("Multiplication Result = ");
    display(&poly3);

    return 0;
}
