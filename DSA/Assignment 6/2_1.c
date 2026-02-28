#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 1000

int history[MAX];
int top = -1;

void pushHistory(int x) {
    history[++top] = x;
}

void popHistory() {
    if (top >= 0) top--;
}

int peekHistory() {
    if (top >= 0) return history[top];
    return -1;
}

void clearHistory() {
    top = -1;
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

int applyOp(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;  
    }
    return 0;
}

int evaluate(char *exp) {
    int values[MAX], vtop = -1;
    char ops[MAX];
    int otop = -1;

    for (int i = 0; exp[i]; i++) {

        if (isspace(exp[i]))
            continue;

        if (isdigit(exp[i])) {
            int val = 0;
            while (i < strlen(exp) && isdigit(exp[i])) {
                val = val * 10 + (exp[i] - '0');
                i++;
            }
            values[++vtop] = val;
            i--;
        }

        else if (exp[i] == '(') {
            ops[++otop] = exp[i];
        }

        else if (exp[i] == ')') {
            while (otop >= 0 && ops[otop] != '(') {
                int b = values[vtop--];
                int a = values[vtop--];
                char op = ops[otop--];
                values[++vtop] = applyOp(a, b, op);
            }
            otop--; 
        }

        else {
            while (otop >= 0 && precedence(ops[otop]) >= precedence(exp[i])) {
                int b = values[vtop--];
                int a = values[vtop--];
                char op = ops[otop--];
                values[++vtop] = applyOp(a, b, op);
            }
            ops[++otop] = exp[i];
        }
    }

    while (otop >= 0) {
        int b = values[vtop--];
        int a = values[vtop--];
        char op = ops[otop--];
        values[++vtop] = applyOp(a, b, op);
    }

    return values[vtop];
}

int main() {
    int N;
    scanf("%d", &N);
    getchar();  

    while (N--) {
        char cmd[10];
        char expr[100];

        scanf("%s", cmd);

        if (strcmp(cmd, "EVAL") == 0) {
            getchar(); 
            fgets(expr, sizeof(expr), stdin);
            expr[strcspn(expr, "\n")] = 0;

            int result = evaluate(expr);
            pushHistory(result);
        }
        else if (strcmp(cmd, "LAST") == 0) {
            printf("%d\n", peekHistory());
        }
        else if (strcmp(cmd, "UNDO") == 0) {
            popHistory();
        }
        else if (strcmp(cmd, "CLEAR") == 0) {
            clearHistory();
        }
    }

    return 0;
}
