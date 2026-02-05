#include <stdio.h>

int main() {
    float num;
    printf("Enter a decimal number: ");
    scanf("%f", &num);

    union {
        float f;
        unsigned int i;
    } data;

    data.f = num;
    unsigned int bits = data.i;

    int sign = (bits >> 31) & 1;
    int exponent = (bits >> 23) & 0xFF;
    unsigned int mantissa = bits & 0x7FFFFF;

    printf("\nIEEE-754 Single Precision Representation:\n");
    printf("32-bit Format : ");
    for (int i = 31; i >= 0; i--) {
        printf("%d", (bits >> i) & 1);
        if (i == 31 || i == 23)
            printf(" ");
    }

    return 0;
}


//     printf("Sign Bit  : %d\n", sign);
//     printf("Exponent  : ");

//     for (int i = 7; i >= 0; i--) {
//         printf("%d", (exponent >> i) & 1);
//     }

//     printf(" (biased: %d)\n", exponent);

//     printf("Mantissa     : ");
//     for (int i = 22; i >= 0; i--) {
//         printf("%d", (mantissa >> i) & 1);
//     }