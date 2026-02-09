#include<stdio.h> 
#include<stdlib.h>

struct link{
    int data;
    struct link *next;
};
typedef struct link node;

node* newNode(int data) {
    node* temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void append(node** head, int data) {
    node* temp = newNode(data);
    if (*head == NULL) {
        *head = temp;
        return;
    }
    node* curr = *head;
    while (curr->next != NULL)
        curr = curr->next;
    curr->next = temp;
}

void printList(node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void rearrangeEvenOdd(node** head) {
    if (*head == NULL || (*head)->next == NULL)
        return;

    node *evenHead = NULL, *evenTail = NULL;
    node *oddHead = NULL, *oddTail = NULL;

    node* curr = *head;
    int pos = 1;

    while (curr != NULL) {
        node* nextNode = curr->next;
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
        pos++;
        curr = nextNode;
    }
    if (evenHead == NULL) {
        *head = oddHead;
        return;
    }
    evenTail->next = oddHead;
    *head = evenHead;  
}

int main(){ 
    struct link* head = NULL;
    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);
    append(&head, 5);
    append(&head, 6);

    printf("Original List:\n");
    printList(head);
    rearrangeEvenOdd(&head);
    printf("Modified List:\n");
    printList(head);
return 0;
}