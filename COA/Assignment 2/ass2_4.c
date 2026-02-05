#include <stdio.h>

int main() {

    float f = 1.0f / 3.0f;
    double d = 1.0 / 3.0;

    printf("Division: 1 / 3\n\n");

    printf("float  value  : %.20f\n", f);
    printf("double value  : %.20lf\n", d);

    printf("\nDifference (double - float): %.20lf\n", d - f);

    return 0;
}
