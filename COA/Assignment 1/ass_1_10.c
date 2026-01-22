#include <stdio.h>

int binaryToDecimal(long int binary) {
    int decimal = 0, base = 1, digit;
    while (binary > 0) {
        digit = binary % 10;
        decimal += digit * base;
        base *= 2;
        binary /= 10;
    }
    return decimal;
}

long int decimalToBinary(int decimal) {
    long int binary = 0;
    int rem, base = 1;
    while (decimal > 0) {
        rem = decimal % 2;
        binary += rem * base;
        base *= 10;
        decimal /= 2;
    }
    return binary;
}

int main() {
    long int bin1, bin2;
    int dec1, dec2, result;
    int choice;

    printf("Enter Binary numbers:");
    scanf("%ld", &bin1);
    scanf("%ld", &bin2);

    dec1 = binaryToDecimal(bin1);
    dec2 = binaryToDecimal(bin2);

    printf("MENU\n");
    printf("1. Addition\n");
    printf("2. Multiplication\n");
    printf("3. Division\n");
    printf("Enter your choice: \n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            result = dec1 + dec2;
            printf("Binary Sum = %ld\n", decimalToBinary(result));
            break;

        case 2:
            result = dec1 * dec2;
            printf("Binary Product = %ld\n", decimalToBinary(result));
            break;

        case 3:
            if (dec2 == 0) {
                printf("Division by zero not possible\n");
            } else {
                result = dec1 / dec2;
                printf("Binary Quotient = %ld\n", decimalToBinary(result));
            }
            break;

        default:
            printf("Invalid choice\n");
    }

    return 0;
}
