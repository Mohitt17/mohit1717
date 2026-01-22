#include <stdio.h>
#include <string.h>

void onesComplement(char b[]) {
    for (int i = 0; i < strlen(b); i++) {
        b[i] = (b[i] == '0') ? '1' : '0';
    }
}

int binaryAdd(char a[], char b[], char result[]) {
    int carry = 0;
    int n = strlen(a);

    for (int i = n - 1; i >= 0; i--) {
        int sum = (a[i] - '0') + (b[i] - '0') + carry;
        result[i] = (sum % 2) + '0';
        carry = sum / 2;
    }

    result[n] = '\0';
    return carry;
}

int main() {
    char a[20], b[20], result[20];

    printf("Enter minuend (A): ");
    scanf("%s", a);

    printf("Enter subtrahend (B): ");
    scanf("%s", b);

    if (strlen(a) != strlen(b)) {
        printf("Error: Both numbers must have same length.\n");
        return 0;
    }

    onesComplement(b);

    int carry = binaryAdd(a, b, result);

    if (carry == 1) {
        for (int i = strlen(result) - 1; i >= 0; i--) {
            if (result[i] == '0') {
                result[i] = '1';
                break;
            } else {
                result[i] = '0';
            }
        }
        printf("\nResult (Positive): %s\n", result);
    } else {
        onesComplement(result);
        printf("\nResult (Negative): -%s\n", result);
    }

    int valid = 0;
    for (int i = 0; i < strlen(result); i++) {
        if (result[i] == '0') {
            valid = 1;
            break;
        }
    }

    if (!valid)
        printf("Validation: Invalid result (Negative Zero)\n");
    else
        printf("Validation: Valid result\n");

    return 0;
}
