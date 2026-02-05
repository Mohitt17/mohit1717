#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);

        int a[n];
        int total2 = 0;

        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            if (a[i] == 2)
                total2++;
        }

        if (total2 % 2 != 0) {
            printf("-1\n");
            continue;
        }

        int need = total2 / 2;
        int pref2 = 0;
        int ans = -1;

        for (int i = 0; i < n - 1; i++) {
            if (a[i] == 2)
                pref2++;

            if (pref2 == need) {
                ans = i + 1; 
                break;
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}
