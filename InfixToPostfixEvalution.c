#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int precedence(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    if (c == '^') return 3;
    return 0;
}

void infixToPostfix(char infix[100], char postfix[100]) {
    char stack[100];
    int top = -1;
    int j = 0;
    for (int i = 0; infix[i]; i++) {
        char c = infix[i];
        if (isalpha(c))
            postfix[j++] = c;
        else if (c == '(')
            stack[++top] = c;
        else if (c == ')') {
            while (top >= 0 && stack[top] != '(')
                postfix[j++] = stack[top--];
            if (top >= 0 && stack[top] == '(') top--;
        } else {
            while (top >= 0 && precedence(stack[top]) >= precedence(c))
                postfix[j++] = stack[top--];
            stack[++top] = c;
        }
    }
    while (top >= 0) {
        if (stack[top] != '(')
            postfix[j++] = stack[top--];
        else
            top--;
    }
    postfix[j] = '\0';
}

int evaluatePostfix(char postfix[100]) {
    int stack[100];
    int top = -1;
    for (int i = 0; postfix[i]; i++) {
        char c = postfix[i];
        if (isalpha(c)) {
            int operand;
            printf("Enter Value of %c: ", c);
            scanf("%d", &operand);
            stack[++top] = operand;
        } else {
            int b = stack[top--];
            int a = stack[top--];
            int result;
            switch (c) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': result = a / b; break;
                case '^': result = (int)pow(a, b); break;
            }
            stack[++top] = result;
        }
    }
    return stack[0];
}

int main() {
    char infix[100];
    char postfix[100];

    printf("Enter Infix Expression: ");
    scanf("%s", infix);
    infixToPostfix(infix, postfix);
    printf("\nPostfix expression: %s\n", postfix);
    int result = evaluatePostfix(postfix);
    printf("Result of the Expression is %d\n", result);
    return 0;
}
