#include <stdio.h>
#include <string.h>

int main() {
    char a[50], b[50], sum[50];
    int i, carry = 0, n;
     int valid = 0;

    printf("Enter binary number: ");
    scanf("%s", a);
    scanf("%s", b);

    n = strlen(a);

    for (i = n - 1; i >= 0; i--) {
        int total = (a[i] - '0') + (b[i] - '0') + carry;
        sum[i] = (total % 2) + '0';
        carry = total / 2;
    }

    if (carry == 1) {
        carry = 1;
        for (i = n - 1; i >= 0; i--) {
            int total = (sum[i] - '0') + carry;
            sum[i] = (total % 2) + '0';
            carry = total / 2;
        }
    }
    sum[n] = '\0';
    for (int i = 0; i < strlen(sum); i++) {
        if (sum[i] == '0') {
            valid = 1;
            break;
        }
    }

    printf(" \n  Final Result (1's Complement Arithmetic): %s \n", sum);
    
    if (!valid)
        printf("Validation: Invalid result (Negative Zero)\n");
    else
        printf("Validation: Valid result\n");

    return 0;
}


