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

void addPatient() {
    struct Patient *newNode, *temp;
    newNode = (struct Patient *)malloc(sizeof(struct Patient));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter Patient ID: ");
    scanf("%d", &newNode->id);

    printf("Enter Patient Name: ");
    scanf(" %[^\n]", newNode->name);

    printf("Enter Patient Age: ");
    scanf("%d", &newNode->age);

    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }

    printf("Patient added successfully!\n");
}

void displayPatients() {
    struct Patient *temp = head;

    if (head == NULL) {
        printf("Waiting list is empty.\n");
        return;
    }

    printf("\n--- Waiting Patients ---\n");
    while (temp != NULL) {
        printf("ID: %d | Name: %s | Age: %d\n",
               temp->id, temp->name, temp->age);
        temp = temp->next;
    }
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
        printf("\n===== Hospital Waiting List Menu =====\n");
        printf("1. Add New Patient\n");
        printf("2. Display Waiting Patients\n");
        printf("3. Count Total Patients\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addPatient();
            break;
        case 2:
            displayPatients();
            break;
        case 3:
            countPatients();
            break;
        case 4:
            printf("Exiting safely...\n");
            break;
        default:
            printf("Invalid choice! Try again.\n");
        }
    } while (choice != 4);

    return 0;
}
