#include <stdio.h>
#include <string.h>

#define MAX 1000

char stack[MAX];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

int isMatching(char open, char close) {
    if (open == '(' && close == ')') return 1;
    if (open == '{' && close == '}') return 1;
    if (open == '[' && close == ']') return 1;
    return 0;
}

int main() {
    char expr[MAX];
    scanf("%s", expr);

    for (int i = 0; expr[i] != '\0'; i++) {
        char ch = expr[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (top == -1) {
                printf("NOT BALANCED\n");
                return 0;
            }
            char open = pop();
            if (!isMatching(open, ch)) {
                printf("NOT BALANCED\n");
                return 0;
            }
        }
    }

    if (top == -1)
        printf("BALANCED\n");
    else
        printf("NOT BALANCED\n");

    return 0;
}