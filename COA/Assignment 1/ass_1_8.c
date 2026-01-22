#include <stdio.h>
#include <string.h>

int main() {
    char binary[50], ones[50], twos[50];
    int i, carry = 1;

    scanf("%s", binary);

    for (i = 0; binary[i] != '\0'; i++) {
        if (binary[i] == '0')
            ones[i] = '1';
        else
            ones[i] = '0';
    }
    ones[i] = '\0';

    strcpy(twos, ones);

    for (i = strlen(twos) - 1; i >= 0; i--) {
        if (twos[i] == '1' && carry == 1) {
            twos[i] = '0';
        } else if (twos[i] == '0' && carry == 1) {
            twos[i] = '1';
            carry = 0;
        }
    }

    printf("1's Complement = %s\n", ones);
    printf("2's Complement = %s\n", twos);

    return 0;
}
