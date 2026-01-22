#include <stdio.h>
#include <string.h>

int main() {
    char bin1[50], bin2[50], result[51];
    int i, j, k, carry = 0;
    int sum;

    scanf("%s", bin1);
    scanf("%s", bin2);

    i = strlen(bin1) - 1;
    j = strlen(bin2) - 1;
    k = 0;
    while (i >= 0 || j >= 0) {
        sum = carry;

        if (i >= 0)
            sum += bin1[i--] - '0';
        if (j >= 0)
            sum += bin2[j--] - '0';

        result[k++] = (sum % 2) + '0';
        carry = sum / 2;
    }

    if (carry)
        result[k++] = '1';

    result[k] = '\0';

    for (i = 0, j = k - 1; i < j; i++, j--) {
        char temp = result[i];
        result[i] = result[j];
        result[j] = temp;
    }

    printf("Binary Sum = %s\n", result);

    return 0;
}
