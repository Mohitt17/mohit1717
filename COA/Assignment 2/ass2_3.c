#include <stdio.h>

int main() {

    double a = 0.1;
    double b = 0.2;
    double c = a + b;

    printf("Expression 1: 0.1 + 0.2\n");
    printf("Expected (Math) : 0.3\n");
    printf("Computed Result : %.17f\n\n", c);

    double x = 1e20;
    double y = (x + 1) - x;

    printf("Expression 2: (1e20 + 1) - 1e20\n");
    printf("Expected (Math) : 1\n");
    printf("Computed Result : %.0f\n", y);

    return 0;
}
