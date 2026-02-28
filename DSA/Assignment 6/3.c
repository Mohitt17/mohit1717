#include <stdio.h>
#include <string.h>

#define MAX 1000

typedef struct
{
    char arr[MAX];
    int top;
} Stack;

void init(Stack *s)
{
    s->top = -1;
}

int isEmpty(Stack *s)
{
    return s->top == -1;
}

void push(Stack *s, char c)
{
    s->arr[++s->top] = c;
}

char pop(Stack *s)
{
    return s->arr[s->top--];
}

int isMatching(char open, char close)
{
    if (open == '(' && close == ')')
        return 1;
    if (open == '{' && close == '}')
        return 1;
    if (open == '[' && close == ']')
        return 1;
    return 0;
}

int main()
{
    Stack s;
    init(&s);

    char exp[MAX];
    scanf("%s", exp);

    for (int i = 0; exp[i] != '\0'; i++)
    {

        char ch = exp[i];

        if (ch == '(' || ch == '{' || ch == '[')
        {
            push(&s, ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            if (isEmpty(&s))
            {
                printf("NOT BALANCED\n");
                return 0;
            }
            char top = pop(&s);
            if (!isMatching(top, ch))
            {
                printf("NOT BALANCED\n");
                return 0;
            }
        }
    }

    if (isEmpty(&s))
        printf("BALANCED\n");
    else
        printf("NOT BALANCED\n");

    return 0;
}
