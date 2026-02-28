#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int id;
    char name[100];
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;
struct Node* tail = NULL;
struct Node* current = NULL;

struct Node* createNode(int id, char name[]) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->id = id;
    strcpy(newNode->name, name);
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void addFront(int id, char name[]) {
    struct Node* newNode = createNode(id, name);

    if (head == NULL) {
        head = tail = current = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void addEnd(int id, char name[]) {
    struct Node* newNode = createNode(id, name);

    if (tail == NULL) {
        head = tail = current = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void deleteSong(int id) {
    struct Node* temp = head;

    while (temp != NULL) {
        if (temp->id == id) {
            if (temp == head) head = temp->next;
            if (temp == tail) tail = temp->prev;
            if (temp->prev) temp->prev->next = temp->next;
            if (temp->next) temp->next->prev = temp->prev;

            if (current == temp) {
                if (temp->next)
                    current = temp->next;
                else
                    current = temp->prev;
            }

            free(temp);
            return;
        }
        temp = temp->next;
    }
}

void nextSong() {
    if (current == NULL || current->next == NULL) {
        printf("END OF PLAYLIST\n");
    } else {
        current = current->next;
        if (current == NULL || current->next == NULL) {
        printf("END OF PLAYLIST\n");
    }
    }
}

void prevSong() {
    if (current == NULL || current->prev == NULL) {
        printf("START OF PLAYLIST\n");
    } else {
        current = current->prev;
        if (current == NULL || current->prev == NULL) {
        printf("START OF PLAYLIST\n");
    }
}
}

void displayForward() {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d %s\n", temp->id, temp->name);
        temp = temp->next;
    }
}

void displayBackward() {
    struct Node* temp = tail;
    while (temp != NULL) {
        printf("%d %s\n", temp->id, temp->name);
        temp = temp->prev;
    }
}

int main() {
    int N;
    // printf("Enter : ");
    scanf("%d", &N);

    char op[30];
    int id;
    char name[100];

    while (N--) {
        scanf("%s", op);

        if (strcmp(op, "ADD_FRONT") == 0) {
            scanf("%d %s", &id, name);
            addFront(id, name);
        } 
        else if (strcmp(op, "ADD_END") == 0) {
            scanf("%d %s", &id, name);
            addEnd(id, name);
        } 
        else if (strcmp(op, "DELETE") == 0) {
            scanf("%d", &id);
            deleteSong(id);
        } 
        else if (strcmp(op, "NEXT") == 0) {
            nextSong();
        } 
        else if (strcmp(op, "PREV") == 0) {
            prevSong();
        } 
        else if (strcmp(op, "DISPLAY_FORWARD") == 0) {
            displayForward();
        } 
        else if (strcmp(op, "DISPLAY_BACKWARD") == 0) {
            displayBackward();
        }
    }
    return 0;
}