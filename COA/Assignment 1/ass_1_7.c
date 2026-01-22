#include <stdio.h>
#include <string.h>

int main() {
    char hex[20];
    int i;

    char binary[] = {
        "0000", "0001", "0010", "0011",
        "0100", "0101", "0110", "0111",
        "1000", "1001", "1010", "1011",
        "1100", "1101", "1110", "1111"
    };

    scanf("%s", hex);

    printf("Binary equivalent: ");

    for (i = 0; hex[i] != '\0'; i++) {
        if (hex[i] >= '0' && hex[i] <= '9') {
            printf("%s", binary[hex[i] - '0']);
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            printf("%s", binary[hex[i] - 'A' + 10]);
        } else if (hex[i] >= 'a' && hex[i] <= 'f') {
            printf("%s", binary[hex[i] - 'a' + 10]);
        } else {
            printf("\nInvalid hexadecimal digit!");
            return 1;
        }
    }

    return 0;
}
