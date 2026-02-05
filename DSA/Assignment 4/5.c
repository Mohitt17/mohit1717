#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* createNode(int data) {
    struct Node *n = (struct Node*)malloc(sizeof(struct Node));
    n->data = data;
    n->next = NULL;
    return n;
}

struct Node* destroyUnstable(struct Node *head, int K) {
    if (K <= 1 || head == NULL) return head;

    struct Node dummy;
    dummy.next = head;

    struct Node *prev = &dummy;
    struct Node *start = head;

    while (start != NULL) {
        struct Node *temp = start;
        int count = 0;

        int maxVal = temp->data, minVal = temp->data;
        int maxPos = 0, minPos = 0, idx = 0;

        while (temp != NULL && count < K) {
            if (temp->data > maxVal) {
                maxVal = temp->data;
                maxPos = idx;
            }
            if (temp->data < minVal) {
                minVal = temp->data;
                minPos = idx;
            }
            temp = temp->next;
            idx++;
            count++;
        }

        if (count < K) break;

        if (maxPos < minPos) {
            temp = start;
            for (int i = 0; i < K; i++) {
                struct Node *del = temp;
                temp = temp->next;
                free(del);
            }

            prev->next = temp;
            start = temp;   
        } else {
            prev = start;
            start = start->next;
        }
    }

    return dummy.next;
}

void printList(struct Node *head) {
    if (head == NULL) {
        printf("-1\n");
        return;
    }
    printf("%d\n", head->data);
}

int main() {
    int n, k, x;
    struct Node *head = NULL, *tail = NULL;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        struct Node *node = createNode(x);
        if (head == NULL)
            head = tail = node;
        else {
            tail->next = node;
            tail = node;
        }
    }

    printf("Enter K: ");
    scanf("%d", &k);

    head = destroyUnstable(head, k);
    printList(head);

    return 0;
}
