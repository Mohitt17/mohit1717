#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Request {
    int id;
    char name[50];
    float distance;
    float fare;
    struct Request* next;
};

struct Request* newRequest(int id, char name[], float dist, float fare) {
    struct Request* temp = (struct Request*)malloc(sizeof(struct Request));
    temp->id = id;
    strcpy(temp->name, name);
    temp->distance = dist;
    temp->fare = fare;
    temp->next = NULL;
    return temp;
}

void insertRequest(struct Request** head, int id, char name[], float dist, float fare) {
    struct Request* temp = newRequest(id, name, dist, fare);

    if (*head == NULL ||
        (*head)->distance > dist ||
        ((*head)->distance == dist && (*head)->fare < fare)) {
        temp->next = *head;
        *head = temp;
        return;
    }

    struct Request* curr = *head;
    while (curr->next != NULL &&
          (curr->next->distance < dist ||
          (curr->next->distance == dist && curr->next->fare >= fare))) {
        curr = curr->next;
    }

    temp->next = curr->next;
    curr->next = temp;
}

void display(struct Request* head) {
    if (head == NULL) {
        printf("No active ride requests.\n");
        return;
    }

    printf("\nCurrent Ride Requests (Nearest First):\n");
    while (head != NULL) {
        printf("ID: %d | Name: %s | Distance: %.2f | Fare: %.2f\n",
               head->id, head->name, head->distance, head->fare);
        head = head->next;
    }
}

void serveNearest(struct Request** head) {
    if (*head == NULL) {
        printf("No requests to serve.\n");
        return;
    }

    struct Request* temp = *head;
    printf("\nRequest found and served:\n");
    printf("ID: %d | Name: %s | Distance: %.2f | Fare: %.2f\n",
           temp->id, temp->name, temp->distance, temp->fare);

    *head = temp->next;
    free(temp);
}

int countRequests(struct Request* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

void cancelRequest(struct Request** head, int id) {
    if (*head == NULL) {
        printf("No active requests.\n");
        return;
    }

    struct Request* curr = *head;
    struct Request* prev = NULL;

    while (curr != NULL && curr->id != id) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL) {
        printf("Request ID %d not found.\n", id);
        return;
    }

    if (prev == NULL)
        *head = curr->next;
    else
        prev->next = curr->next;

    free(curr);
    printf("Request canceled successfully.\n");
}

int main() {
    struct Request* head = NULL;
    int choice;

    while (1) {
        printf("\n--- Pickup Request Manager ---\n");
        printf("1. Insert new request\n");
        printf("2. Display all requests\n");
        printf("3. Serve nearest request\n");
        printf("4. Count active requests\n");
        printf("5. Cancel request by ID\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            int id;
            char name[50];
            float dist, fare;

            printf("Enter Request ID: ");
            scanf("%d", &id);
            printf("Enter Customer Name: ");
            scanf("%s", name);
            printf("Enter Distance: ");
            scanf("%f", &dist);
            printf("Enter Fare: ");
            scanf("%f", &fare);

            insertRequest(&head, id, name, dist, fare);
            printf("Request inserted successfully.\n");
        }
        else if (choice == 2) {
            display(head);
        }
        else if (choice == 3) {
            serveNearest(&head);
        }
        else if (choice == 4) {
            printf("Total active requests: %d\n", countRequests(head));
        }
        else if (choice == 5) {
            int id;
            printf("Enter Request ID to cancel: ");
            scanf("%d", &id);
            cancelRequest(&head, id);
        }
        else if (choice == 6) {
            if (head == NULL)
                printf("All rides completed.\n");
            else
                printf("Some rides are still pending.\n");
            break;
        }
        else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}
