#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 1000

typedef struct
{
    int arr[MAX];
    int top;
} IntStack;

typedef struct
{
    char arr[MAX];
    int top;
} CharStack;

void initIntStack(IntStack *s) { s->top = -1; }
void initCharStack(CharStack *s) { s->top = -1; }

int isEmptyInt(IntStack *s) { return s->top == -1; }
int isEmptyChar(CharStack *s) { return s->top == -1; }

void pushInt(IntStack *s, int x) { s->arr[++s->top] = x; }
int popInt(IntStack *s) { return s->arr[s->top--]; }
int peekInt(IntStack *s) { return s->arr[s->top]; }

void pushChar(CharStack *s, char c) { s->arr[++s->top] = c; }
char popChar(CharStack *s) { return s->arr[s->top--]; }
char peekChar(CharStack *s) { return s->arr[s->top]; }

int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

int applyOp(int a, int b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return b != 0 ? a / b : 0;
    }
    return 0;
}

int evaluate(char *exp)
{
    IntStack values;
    CharStack ops;
    initIntStack(&values);
    initCharStack(&ops);

    for (int i = 0; exp[i] != '\0'; i++)
    {

        if (isspace(exp[i]))
            continue;

        if (isdigit(exp[i]))
        {
            int val = 0;
            while (i < strlen(exp) && isdigit(exp[i]))
            {
                val = val * 10 + (exp[i] - '0');
                i++;
            }
            i--;
            pushInt(&values, val);
        }

        else if (exp[i] == '(')
        {
            pushChar(&ops, exp[i]);
        }

        else if (exp[i] == ')')
        {
            while (!isEmptyChar(&ops) && peekChar(&ops) != '(')
            {
                int b = popInt(&values);
                int a = popInt(&values);
                char op = popChar(&ops);
                pushInt(&values, applyOp(a, b, op));
            }
            popChar(&ops);
        }

        else
        {
            while (!isEmptyChar(&ops) && precedence(peekChar(&ops)) >= precedence(exp[i]))
            {
                int b = popInt(&values);
                int a = popInt(&values);
                char op = popChar(&ops);
                pushInt(&values, applyOp(a, b, op));
            }
            pushChar(&ops, exp[i]);
        }
    }

    while (!isEmptyChar(&ops))
    {
        int b = popInt(&values);
        int a = popInt(&values);
        char op = popChar(&ops);
        pushInt(&values, applyOp(a, b, op));
    }

    return popInt(&values);
}

int main()
{
    int N;
    scanf("%d", &N);
    getchar();

    IntStack history;
    initIntStack(&history);

    while (N--)
    {
        char line[200];
        fgets(line, sizeof(line), stdin);

        if (strncmp(line, "EVAL", 4) == 0)
        {
            char expr[150];
            strcpy(expr, line + 5);
            int result = evaluate(expr);
            pushInt(&history, result);
        }

        else if (strncmp(line, "LAST", 4) == 0)
        {
            if (!isEmptyInt(&history))
                printf("%d\n", peekInt(&history));
            else
                printf("EMPTY\n");
        }

        else if (strncmp(line, "UNDO", 4) == 0)
        {
            if (!isEmptyInt(&history))
                popInt(&history);
        }

        else if (strncmp(line, "CLEAR", 5) == 0)
        {
            initIntStack(&history);
        }
    }

    return 0;
}
