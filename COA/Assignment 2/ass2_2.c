#include <stdio.h>

void decimalToBinary(double num, int bits) {
    printf("Binary (up to %d bits): 0.", bits);

    for (int i = 0; i < bits; i++) {
        num *= 2;
        int bit = (int)num;
        printf("%d", bit);
        num -= bit;
    }
    printf("\n");
}

int main() {
    double nums[] = {0.1, 0.2, 0.3};
    int bits = 20;

    for (int i = 0; i < 3; i++) {
        double x = nums[i];
        float stored = (float)x;

        printf("\nDecimal Value      : %.10f\n", x);
        decimalToBinary(x, bits);
        printf("Stored (float)     : %.10f\n", stored);
        printf("Difference         : %.10e\n", stored - x);
    }

    return 0;
}
