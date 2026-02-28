#include <stdio.h>

#define MAX 1000

typedef struct
{
    int arr[MAX];
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

void push(Stack *s, int x)
{
    s->arr[++s->top] = x;
}

int pop(Stack *s)
{
    return s->arr[s->top--];
}

int peek(Stack *s)
{
    return s->arr[s->top];
}

int main()
{
    int N;
    scanf("%d", &N);

    int order[MAX];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &order[i]);
    }

    Stack s;
    init(&s);

    int nextArrival = 1;
    int i = 0;

    while (i < N)
    {
        if (!isEmpty(&s) && peek(&s) == order[i])
        {
            pop(&s);
            i++;
        }
        else if (nextArrival <= N)
        {
            push(&s, nextArrival);
            nextArrival++;
        }
        else
        {
            break;
        }
    }

    if (i == N)
        printf("POSSIBLE\n");
    else
        printf("IMPOSSIBLE\n");

    return 0;
}
