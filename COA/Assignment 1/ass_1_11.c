#include <stdio.h>
#include <math.h>

void decimalToBinary(int num, int bits, int binary[]) {
    int i;
    for (i = bits - 1; i >= 0; i--) {
        binary[i] = num % 2;
        num = num / 2;
    }
}

void onesComplement(int binary[], int bits) {
    for (int i = 0; i < bits; i++) {
        binary[i] = (binary[i] == 0) ? 1 : 0;
    }
}

void twosComplement(int binary[], int bits) {
    int carry = 1;
    for (int i = bits - 1; i >= 0; i--) {
        int sum = binary[i] + carry;
        binary[i] = sum % 2;
        carry = sum / 2;
    }
}

void displayBinary(int binary[], int bits) {
    for (int i = 0; i < bits; i++) {
        printf("%d", binary[i]);
    }
    printf("\n");
}

int main() {
    int number, bits;
    int binary[32];

    printf("Enter decimal number: ");
    scanf("%d", &number);

    printf("Enter word length (bits): ");
    scanf("%d", &bits);

    int absNum = abs(number);
    decimalToBinary(absNum, bits, binary);

    if (number < 0) {
        onesComplement(binary, bits);
        twosComplement(binary, bits);
        printf("2's Complement Representation: ");
    } else {
        printf("Binary Representation: ");
    }

    displayBinary(binary, bits);

    int min = -pow(2, bits - 1);
    int max = pow(2, bits - 1) - 1;

    printf("Range for %d-bit word: %d to %d\n", bits, min, max);

    return 0;
}
