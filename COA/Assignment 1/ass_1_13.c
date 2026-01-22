#include <stdio.h>
#include <string.h>

void binaryAdd(char a[], char b[], char result[], int *carryOut) {
    int n = strlen(a);
    int carry = 0;

    for (int i = n - 1; i >= 0; i--) {
        int sum = (a[i] - '0') + (b[i] - '0') + carry;
        result[i] = (sum % 2) + '0';
        carry = sum / 2;
    }

    *carryOut = carry;
    result[n] = '\0';
}

int main() {
    char a[20], b[20], result[20];
    int carryOut;

    printf("Enter binary number: ");
    scanf("%s", a);
    scanf("%s", b);

    if (strlen(a) != strlen(b)) {
        printf("Error: Binary numbers must be of same length.\n");
        return 0;
    }

    binaryAdd(a, b, result, &carryOut);

    printf("\nSigned 2's Complement Result: %s\n", result);
    printf("Unsigned Carry Out: %d\n", carryOut);

    if ((a[0] == b[0]) && (result[0] != a[0])) {
        printf("Overflow Detected \n");
    } else {
        printf("No Overflow \n");
    }

    return 0;
}
