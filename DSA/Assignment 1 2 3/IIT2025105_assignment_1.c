#include <stdio.h>
#include <string.h>

#define MAX 200

struct Train {
    int trainNo;
    char zone[15];
    char source[20];
    char destination[20];
    int platformNo;
    int departureTime;
    int arrivalTime;
};

struct Train trains[MAX];
int totalTrains = 0;

/* Comparison function */
int compare(struct Train a, struct Train b) {
    if (a.departureTime != b.departureTime)
        return a.departureTime - b.departureTime;
    if (a.platformNo != b.platformNo)
        return a.platformNo - b.platformNo;
    return a.trainNo - b.trainNo;
}

/* Merge function */
void merge(struct Train arr[], int left, int mid, int right) {
    struct Train temp[MAX];
    int i = left, j = mid + 1, k = left;

    while (i <= mid && j <= right) {
        if (compare(arr[i], arr[j]) <= 0)
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for (i = left; i <= right; i++)
        arr[i] = temp[i];
}

/* Recursive Merge Sort */
void mergeSort(struct Train arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

/* Load zone-wise timetable */
void loadZone() {
    int n;
    printf("Enter number of trains in zone: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Train %d details:\n", i + 1);
        scanf("%d %s %s %s %d %d %d",
              &trains[totalTrains].trainNo,
              trains[totalTrains].zone,
              trains[totalTrains].source,
              trains[totalTrains].destination,
              &trains[totalTrains].platformNo,
              &trains[totalTrains].departureTime,
              &trains[totalTrains].arrivalTime);
        totalTrains++;
    }
}

/* Display timetable */
void displayTimetable() {
    printf("\nNational Timetable (Sorted):\n");
    printf("TrainNo Zone Platform Departure Arrival\n");
    for (int i = 0; i < totalTrains; i++) {
        printf("%d %s %d %d %d\n",
               trains[i].trainNo,
               trains[i].zone,
               trains[i].platformNo,
               trains[i].departureTime,
               trains[i].arrivalTime);
    }
}

/* Detect platform conflicts */
void detectConflicts() {
    int conflict = 0;
    for (int i = 0; i < totalTrains - 1; i++) {
        if (trains[i].platformNo == trains[i + 1].platformNo &&
            trains[i + 1].departureTime < trains[i].arrivalTime) {

            printf("Platform Conflict Detected:\n");
            printf("Platform %d -> Train %d and Train %d\n",
                   trains[i].platformNo,
                   trains[i].trainNo,
                   trains[i + 1].trainNo);
            conflict = 1;
        }
    }

    if (!conflict)
        printf("No platform conflicts detected.\n");
}

/* MAIN MENU */
int main() {
    int choice;

    do {
        printf("\n--- National Railway Timetable System ---\n");
        printf("1. Load Zone-Wise Timetable\n");
        printf("2. Merge & Sort National Timetable\n");
        printf("3. Display Consolidated Timetable\n");
        printf("4. Detect Platform Conflicts\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                loadZone();
                break;
            case 2:
                mergeSort(trains, 0, totalTrains - 1);
                printf("Timetable merged and sorted successfully.\n");
                break;
            case 3:
                displayTimetable();
                break;
            case 4:
                detectConflicts();
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 5);

    return 0;
}
 




