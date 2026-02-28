#include <stdio.h>
#include <string.h>

#define MAX 1000

int queue[MAX];
int front = 0, rear = -1, size = 0;

int isEmpty() {
    return size == 0;
}

void enqueue(int x) {
    if (rear < MAX - 1) {
        rear++;
        queue[rear] = x;
        size++;
    }
}

void dequeue() {
    if (isEmpty()) {
        printf("EMPTY\n");
    } else {
        front++;
        size--;
    }
}

void printFront() {
    if (isEmpty()) {
        printf("EMPTY\n");
    } else {
        printf("%d\n", queue[front]);
    }
}

void printSize() {
    printf("%d\n", size);
}

int main() {
    int N;
    // printf("Enter : ");
    scanf("%d", &N);

    char op[20];
    int x;

    for (int i = 0; i < N; i++) {
        scanf("%s", op);

        if (strcmp(op, "ENQUEUE") == 0) {
            scanf("%d", &x);
            enqueue(x);
        } 
        else if (strcmp(op, "DEQUEUE") == 0) {
            dequeue();
        } 
        else if (strcmp(op, "FRONT") == 0) {
            printFront();
        } 
        else if (strcmp(op, "SIZE") == 0) {
            printSize();
        }
    }

    return 0;
}