#include <stdio.h>

int main() {
    int t;
    scanf("%d", & t);

    while (t--) {
        int n;
        scanf("%d", & n);
        int a[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", & a[i]);
        }
        int w = 0;
        int p = 0;
        for (int i = 0; i < n; i++) {

            for (int j = 0; j < 2; j++) {
                if (w == 0) {
                    break;
                }
                else{
                    p += a[i];
                    w--;
                }
            }

            w++;
        }
        printf("%d\n", p);
    }

}