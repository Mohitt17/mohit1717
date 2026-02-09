#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void append(struct Node** head, int data) {
    struct Node* temp = newNode(data);
    if (*head == NULL) {
        *head = temp;
        return;
    }
    struct Node* curr = *head;
    while (curr->next != NULL)
        curr = curr->next;
    curr->next = temp;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

struct Node* reverseKGroup(struct Node* head, int k) {
    if (head == NULL || k <= 1)
        return head;

    struct Node* curr = head;
    struct Node* prevGroupTail = NULL;
    struct Node* newHead = NULL;

    while (curr != NULL) {
        struct Node* temp = curr;
        int count = 0;
        while (temp != NULL && count < k) {
            temp = temp->next;
            count++;
        }

        if (count < k) {
            if (prevGroupTail != NULL)
                prevGroupTail->next = curr;
            break;
        }

        struct Node* prev = NULL;
        struct Node* next = NULL;
        struct Node* groupHead = curr;

        for (int i = 0; i < k; i++) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        if (newHead == NULL)
            newHead = prev;

        if (prevGroupTail != NULL)
            prevGroupTail->next = prev;

        prevGroupTail = groupHead;
    }

    return newHead != NULL ? newHead : head;
}

int main() {
    struct Node* head = NULL;

    int arr[] = {1,2,3,4,5,6,7,8};
    int n = 8;
    int k = 3;

    for (int i = 0; i < n; i++)
        append(&head, arr[i]);

    printf("Original List:\n");
    printList(head);

    head = reverseKGroup(head, k);

    printf("Modified List (Reverse in groups of %d):\n", k);
    printList(head);

    return 0;
}
