#include <stdio.h>

#define MAX 1000

int stack[MAX];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int peek() {
    if (top == -1) return -1;
    return stack[top];
}

int main() {
    int N;
    scanf("%d", &N);

    int order[MAX];
    for (int i = 0; i < N; i++) {
        scanf("%d", &order[i]);
    }

    int nextArrival = 1;

    for (int i = 0; i < N; i++) {
        int need = order[i];
 
        
        while (nextArrival <= N && (top == -1 || peek() != need)) {
            push(nextArrival);
            nextArrival++;
        }

        if (peek() == need) {
            pop();
        } else {
            printf("IMPOSSIBLE\n");
            return 0;
        }
    }

    printf("POSSIBLE\n");
    return 0;
}
