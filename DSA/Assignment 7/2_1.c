#include <stdio.h>

int Index(int n, int petrol[], int cost[]) {
    for (int i = 0; i < n; i++) {
        int tank = 0;
        int count = 0;
        int j = i;

        while (count < n) {
            tank += petrol[j] - cost[j];

            if (tank < 0) {
                break;   
            }

            j = (j + 1) % n;  
            count++;
        }

        if (count == n && tank >= 0) {
            return i; 
        }
    }
    return -1;  
}

int main() {
    int n;
    // printf("Enter : ");
    scanf("%d", &n);

    int petrol[n], cost[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &petrol[i]);

    for (int i = 0; i < n; i++)
        scanf("%d", &cost[i]);

    int ans = Index(n, petrol, cost);

    if (ans == -1)
        printf("IMPOSSIBLE\n");
    else
        printf("\nIndex is %d\n", ans);

    return 0;
}