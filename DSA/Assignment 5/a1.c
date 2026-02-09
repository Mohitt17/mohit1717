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
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}


struct Node* rearrangeEvenOdd(struct Node* head) {
    if (head == NULL || head->next == NULL)
        return head;

    struct Node *evenHead = NULL, *evenTail = NULL;
    struct Node *oddHead = NULL, *oddTail = NULL;

    struct Node* curr = head;
    int pos = 1;

    while (curr != NULL) {
        struct Node* nextNode = curr->next;
        curr->next = NULL;   

        if (pos % 2 == 0) {  
            if (evenHead == NULL) {
                evenHead = evenTail = curr;
            } else {
                evenTail->next = curr;
                evenTail = curr;
            }
        } else {            
            if (oddHead == NULL) {
                oddHead = oddTail = curr;
            } else {
                oddTail->next = curr;
                oddTail = curr;
            }
        }

        curr = nextNode;
        pos++;
    }

  
    if (evenHead == NULL)
        return oddHead;


    evenTail->next = oddHead;
    return evenHead;
}

int main() {
    struct Node* head = NULL;


    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);
    append(&head, 5);
    append(&head, 6);

    printf("Original List:\n");
    printList(head);

    head = rearrangeEvenOdd(head);

    printf("Modified List (Even positions first):\n");
    printList(head);

    return 0;
}
