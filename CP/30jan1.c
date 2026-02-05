#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n, a, b;
        scanf("%d %d %d", &n, &a, &b);

        if (n == 1) {
            printf("Yes\n");
        } else if (a + b <= n - 2) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }

    return 0;
}
