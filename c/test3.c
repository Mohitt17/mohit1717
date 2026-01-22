#include <stdio.h>
#include <math.h>
#include <stdint.h>

// 1
void fibonacci_series(int n) {
    if (n <= 0) {
        printf("Invalid\n");
        return;
    }
    int a = 0, b = 1, temp, i;
    for (i = 0; i < n; i++) {
        printf("%d ", a);
        temp = a + b;
        a = b;
        b = temp;
    }
    printf("\n");
}

// 2
void prime_series(int L, int R) {
    if (L > R || L < 1) {
        printf("None\n");
        return;
    }
    int num, i, is_prime;
    for (num = L; num <= R; num++) {
        if (num < 2) continue;
        is_prime = 1;
        for (i = 2; i*i <= num; i++)
            if (num % i == 0) { is_prime = 0; break; }
        if (is_prime) printf("%d ", num);
    }
    printf("\n");
}

// 3
void arithmetic_progression(int a, int d, int n) {
    if (n <= 0) {
        printf("Invalid\n");
        return;
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int term = a + i*d;
        printf("%d ", term);
        sum += term;
    }
    printf("\n%d\n", sum);
}

// 4
void geometric_progression(int a, int r, int n) {
    if (n <= 0) {
        printf("Invalid\n");
        return;
    }
    int64_t prod = 1, term;
    for (int i = 0; i < n; i++) {
        term = a * pow(r, i);
        printf("%lld ", term);
        prod *= term;
    }
    printf("\n%lld\n", prod);
}

// 5
void alternating_harmonic_series(int k) {
    if (k <= 0) {
        printf("Invalid\n");
        return;
    }
    double sum = 0.0;
    for (int i = 1; i <= k; i++) {
        double term = 1.0 / i;
        if (i % 2 == 0) term = -term;
        sum += term;
    }
    printf("%.6lf\n", sum);
}

// 6. Factorial Series and Cumulative Sum
void factorial_series(int n) {
    if (n <= 0) {
        printf("Invalid\n");
        return;
    }
    int64_t fact = 1, sum = 0;
    for (int i = 1; i <= n; i++) {
        if (i == 0) continue; // skip 0, demonstrate continue
        fact *= i;
        printf("%lld ", fact);
        sum += fact;
    }
    printf("\n%lld\n", sum);
}

// 7. Armstrong Numbers up to N
void armstrong_numbers(int N) {
    if (N <= 0) {
        printf("None\n");
        return;
    }
    int num, temp, sum, digits, d;
    int printed = 0;
    for (num = 1; num <= N; num++) {
        temp = num; digits = 0;
        while (temp) { digits++; temp /= 10; }
        temp = num; sum = 0;
        while (temp) {
            d = temp % 10;
            sum += pow(d, digits);
            temp /= 10;
        }
        if (sum == num) { printf("%d ", num); printed = 1; }
    }
    if (!printed) printf("None\n");
    else printf("\n");
}

// 8. Exponential Series Maclaurin up to n terms
void exponential_maclaurin(double x, int n) {
    if (n <= 0) {
        printf("Invalid\n");
        return;
    }
    double sum = 1.0, term = 1.0;
    for (int k = 1; k < n; k++) {
        term *= x / k;
        sum += term;
    }
    printf("%.6lf\n", sum);
}

// 9. Alternating Log Series up to n terms
void alternating_log_series(double x, int n) {
    if (n <= 0 || x <= -1 || x >= 1) {
        printf("Invalid\n");
        return;
    }
    double sum = 0.0;
    for (int k = 1; k <= n; k++) {
        double sign = (k % 2 == 1) ? 1.0 : -1.0;
        sum += sign * pow(x, k) / k;
    }
    printf("%.6lf\n", sum);
}

// 10. Exponential Series with Tolerance
void exponential_with_tolerance(double x, double eps, int maxN) {
    if (eps <= 0 || maxN < 1) {
        printf("Invalid\n");
        return;
    }
    double sum = 1.0, term = 1.0;
    int k = 1, count = 1;
    do {
        term *= x / k;
        if (fabs(term) < eps) break;
        sum += term;
        k++;
        count++;
    } while (count < maxN);
    printf("%.6lf\n", sum);
    printf("%d\n", count);



    return 0;
}
