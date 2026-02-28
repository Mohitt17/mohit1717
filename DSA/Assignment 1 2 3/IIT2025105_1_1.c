#include <stdio.h>
#include <string.h>

#define MAX 100

struct Patient {
    int patientID;
    char name[50];
    int age;
    int severity;
    int arrivalTime;
    float priorityScore;
};

struct Patient patients[MAX];
int n = 0;


float calculatePriority(int severity, int age, int arrivalTime) {
    return (severity * 5) + (age / 10.0) - (arrivalTime / 60.0);
}


void admitPatient() {
    if (n >= MAX) {
        printf("Patient limit reached \n");
        return;
    }

    struct Patient p;
    int shifts = 0;

    printf("Enter Patient ID: ");
    scanf("%d", &p.patientID);

    printf("Enter Name: ");
    scanf(" %[^\n]", p.name);

    printf("Enter Age: ");
    scanf("%d", &p.age);

    printf("Enter Severity (1-10): ");
    scanf("%d", &p.severity);

    printf("Enter Arrival Time: ");
    scanf("%d", &p.arrivalTime);

    p.priorityScore = calculatePriority(p.severity, p.age, p.arrivalTime);

    int i = n - 1;

   
    while (i >= 0 &&
          (patients[i].priorityScore < p.priorityScore ||
          (patients[i].priorityScore == p.priorityScore &&
           patients[i].arrivalTime > p.arrivalTime))) {

        patients[i + 1] = patients[i];
        shifts++;
        i--;
    }

    patients[i + 1] = p;
    n++;

    printf("Patient inserted successfully.\n");
    printf("Shifts performed: %d\n", shifts);

    if (shifts > n / 2) {
        printf("Warning: Emergency Ward Congestion Detected\n");
    }
}

void displayPatients() {
    if (n == 0) {
        printf("No patients in queue.\n");
        return;
    }

    printf("\n Patient Queue \n");
    for (int i = 0; i < n; i++) {
        printf("ID: %d | Name: %s | Priority: %.2f | Arrival: %d\n",
               patients[i].patientID,
               patients[i].name,
               patients[i].priorityScore,
               patients[i].arrivalTime);
    }
}

void searchPatient() {
    int id;
    printf("Enter Patient ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < n; i++) {
        if (patients[i].patientID == id) {
            printf("Patient Found:\n");
            printf("Name: %s\n", patients[i].name);
            printf("Priority Score: %.2f\n", patients[i].priorityScore);
            return;
        }
    }
    printf("Patient not found.\n");
}

void dischargePatient() {
    if (n == 0) {
        printf("No patients to discharge.\n");
        return;
    }

    printf("Discharged Patient: %s (ID: %d)\n",
           patients[0].name, patients[0].patientID);

    for (int i = 1; i < n; i++) {
        patients[i - 1] = patients[i];
    }
    n--;
}

int main() {
    int n;

    do {
        printf("  Patient Admission System  \n");
        printf("1. Admit New Patient\n");
        printf("2. Display Patient Queue\n");
        printf("3. Search Patient by ID\n");
        printf("4. Discharge Highest Priority Patient\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &n);

        switch (n) {
            case 1:
                admitPatient();
                break;
            case 2:
                displayPatients();
                break;
            case 3:
                searchPatient();
                break;
            case 4:
                dischargePatient();
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (n != 5);

    return 0;
}