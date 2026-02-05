#include <stdio.h>
#include <float.h>

int main()
{
    float x = FLT_MAX;
    float y = FLT_MIN;

    printf("Overflow example:\n");
    printf("FLT_MAX = %e\n", x);

    x = x * 10;
    printf("After overflow = %e\n", x);

    printf("\nUnderflow example:\n");
    printf("FLT_MIN = %e\n", y);

    y = y / 10;
    printf("After underflow = %e\n", y);

    return 0;
}
