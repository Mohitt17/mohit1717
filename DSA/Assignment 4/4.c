#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Patient {
    int id;
    char name[50];
    int age;
    struct Patient *next;
};

struct Patient *head = NULL;

struct Patient* createPatient() {
    struct Patient *newNode =
        (struct Patient*)malloc(sizeof(struct Patient));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    printf("Enter Patient ID: ");
    scanf("%d", &newNode->id);

    printf("Enter Patient Name: ");
    scanf(" %[^\n]", newNode->name);

    printf("Enter Patient Age: ");
    scanf("%d", &newNode->age);

    newNode->next = NULL;
    return newNode;
}

void addEmergencyPatient() {
    struct Patient *newNode = createPatient();
    if (newNode == NULL) return;

    newNode->next = head;
    head = newNode;

    printf("Emergency patient added at front!\n");
}

void addRegularPatient() {
    struct Patient *newNode = createPatient();
    if (newNode == NULL) return;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Patient *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }

    printf("Regular patient added at end!\n");
}

void displayPatients() {
    struct Patient *temp = head;

    if (head == NULL) {
        printf("Waiting list is empty.\n");
        return;
    }

    printf("\n--- Patient Waiting List ---\n");
    while (temp != NULL) {
        printf("ID: %d | Name: %s | Age: %d\n",
               temp->id, temp->name, temp->age);
        temp = temp->next;
    }
}

void removePatient() {
    int id;
    printf("Enter Patient ID to remove: ");
    scanf("%d", &id);

    struct Patient *temp = head, *prev = NULL;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (head->id == id) {
        head = head->next;
        free(temp);
        printf("Patient removed successfully.\n");
        return;
    }

    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Patient not found.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Patient removed successfully.\n");
}

void updatePatient() {
    int id;
    printf("Enter Patient ID to update: ");
    scanf("%d", &id);

    struct Patient *temp = head;

    while (temp != NULL && temp->id != id)
        temp = temp->next;

    if (temp == NULL) {
        printf("Patient not found.\n");
        return;
    }

    printf("Enter new Name: ");
    scanf(" %[^\n]", temp->name);

    printf("Enter new Age: ");
    scanf("%d", &temp->age);

    printf("Patient details updated successfully.\n");
}

void countPatients() {
    int count = 0;
    struct Patient *temp = head;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    printf("Total patients waiting: %d\n", count);
}

int main() {
    int choice;

    do {
        printf("\n===== Hospital Emergency Waiting List =====\n");
        printf("1. Add Emergency Patient (Front)\n");
        printf("2. Add Regular Patient (End)\n");
        printf("3. Display Patients\n");
        printf("4. Remove Patient\n");
        printf("5. Update Patient Details\n");
        printf("6. Count Patients\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addEmergencyPatient();
            break;
        case 2:
            addRegularPatient();
            break;
        case 3:
            displayPatients();
            break;
        case 4:
            removePatient();
            break;
        case 5:
            updatePatient();
            break;
        case 6:
            countPatients();
            break;
        case 7:
            printf("Exiting safely...\n");
            break;
        default:
            printf("Invalid choice! Try again.\n");
        }
    } while (choice != 7);

    return 0;
}
