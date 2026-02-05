#include<stdio.h>
#include<stdlib.h>
#include<float.h>
#include<math.h>
#include<string.h>
#include<limits.h>

// Task 1: IEEE-754 Single Precision Conversion
void ieee754_conversion(float num) {
    printf("\n=== IEEE-754 Single Precision Conversion ===\n");
    printf("Input decimal: %.10f\n", num);
    
    // Get the binary representation using union
    union {
        float f;
        unsigned int i;
    } converter;
    
    converter.f = num;
    unsigned int bits = converter.i;
    
    // Extract components
    unsigned int sign = (bits >> 31) & 1;
    unsigned int exponent = (bits >> 23) & 0xFF;
    unsigned int mantissa = bits & 0x7FFFFF;
    
    printf("\nComponents:\n");
    printf("Sign bit: %u\n", sign);
    printf("Exponent (biased, 8 bits): %u (0x%02X)\n", exponent, exponent);
    printf("Mantissa (23 bits): 0x%06X\n", mantissa);
    
    // Display 32-bit representation
    printf("\n32-bit representation: ");
    for (int i = 31; i >= 0; i--) {
        printf("%u", (bits >> i) & 1);
        if (i == 31 || i == 23) printf(" ");
    }
    printf("\n");
    
    // Interpret the exponent
    if (exponent == 0) {
        printf("Type: Denormalized (subnormal) number\n");
    } else if (exponent == 255) {
        printf("Type: Special value (Infinity or NaN)\n");
    } else {
        printf("Type: Normalized number\n");
        int unbiased_exp = exponent - 127;
        printf("Unbiased exponent: %d\n", unbiased_exp);
    }
}

// Task 2: Decimal to Binary Fraction Conversion
void decimal_to_binary_fraction(float num) {
    printf("\n=== Decimal to Binary Fraction Conversion ===\n");
    printf("Input decimal: %.10f\n", num);
    
    // Separate integer and fractional parts
    int int_part = (int)num;
    float frac_part = num - int_part;
    
    // Convert integer part to binary
    printf("Integer part (binary): ");
    if (int_part == 0) {
        printf("0");
    } else {
        int temp = int_part;
        char binary[32] = "";
        int idx = 0;
        while (temp > 0) {
            binary[idx++] = (temp % 2) ? '1' : '0';
            temp /= 2;
        }
        for (int i = idx - 1; i >= 0; i--) {
            printf("%c", binary[i]);
        }
    }
    
    // Convert fractional part to binary
    printf("\nFractional part (binary, first 32 bits): 0.");
    int count = 0;
    while (frac_part > 0 && count < 32) {
        frac_part *= 2;
        int digit = (int)frac_part;
        printf("%d", digit);
        frac_part -= digit;
        count++;
    }
    if (count == 32 && frac_part > 0) {
        printf(" (repeating/truncated)");
    }
    printf("\n");
    
    // Compare expected vs stored
    union {
        float f;
        unsigned int i;
    } converter;
    converter.f = num;
    
    printf("\nStored value when retrieved: %.15f\n", converter.f);
    printf("Precision loss: %.15e\n", num - converter.f);
}

// Task 3: Floating-Point Precision Error Demonstration
void precision_error_demo() {
    printf("\n=== Floating-Point Precision Error Demonstration ===\n");
    
    // Test case 1: 0.1 + 0.2
    printf("\nTest 1: 0.1 + 0.2\n");
    float f_result = 0.1f + 0.2f;
    double d_result = 0.1 + 0.2;
    printf("Float result:  %.20f\n", f_result);
    printf("Double result: %.20f\n", d_result);
    printf("Expected:      0.30000000000000000000\n");
    printf("Float error:   %.20e\n", f_result - 0.3f);
    printf("Double error:  %.20e\n", d_result - 0.3);
    
    // Test case 2: (1e20 + 1) - 1e20
    printf("\nTest 2: (1e20 + 1) - 1e20\n");
    float f_res2 = (1e20f + 1.0f) - 1e20f;
    double d_res2 = (1e20 + 1.0) - 1e20;
    printf("Float result:  %.20f\n", f_res2);
    printf("Double result: %.20f\n", d_res2);
    printf("Expected:      1.00000000000000000000\n");
    
    // Test case 3: Associativity test
    printf("\nTest 3: Associativity - (a+b)+c vs a+(b+c)\n");
    float a = 0.1f, b = 0.2f, c = 0.3f;
    float res1 = (a + b) + c;
    float res2 = a + (b + c);
    printf("(0.1 + 0.2) + 0.3 = %.20f\n", res1);
    printf("0.1 + (0.2 + 0.3) = %.20f\n", res2);
    printf("Difference: %.20e\n", res1 - res2);
}

// Task 4: Single vs Double Precision Comparison
void single_vs_double_precision() {
    printf("\n=== Single vs Double Precision Comparison ===\n");
    
    // Test: 1/3
    printf("\nTest: 1.0 / 3.0\n");
    float f = 1.0f / 3.0f;
    double d = 1.0 / 3.0;
    printf("Float (32-bit):  %.20f\n", f);
    printf("Double (64-bit): %.20f\n", d);
    printf("Accurate digits in float: ~6-7\n");
    printf("Accurate digits in double: ~15-16\n");
    
    // Test: sqrt(2)
    printf("\nTest: sqrt(2)\n");
    f = (float)sqrt(2.0);
    d = sqrt(2.0);
    printf("Float:  %.20f\n", f);
    printf("Double: %.20f\n", d);
    
    // Test: pi
    printf("\nTest: asin(1.0) * 2 (approximates pi)\n");
    f = (float)(asin(1.0) * 2);
    d = asin(1.0) * 2;
    printf("Float:  %.20f\n", f);
    printf("Double: %.20f\n", d);
    
    printf("\nConclusion: Double precision has more mantissa bits (52 vs 23),\n");
    printf("resulting in ~8 more decimal digits of accuracy.\n");
}

// Task 5: Floating-Point Overflow and Underflow
void overflow_underflow_demo() {
    printf("\n=== Floating-Point Overflow and Underflow ===\n");
    
    // Overflow demonstration
    printf("\nOverflow Demonstration:\n");
    float large = FLT_MAX;
    printf("FLT_MAX: %.10e\n", large);
    printf("FLT_MAX * 2 = %.10e\n", large * 2.0f);
    printf("FLT_MAX * 10 = %.10e\n", large * 10.0f);
    
    // Underflow demonstration
    printf("\nUnderflow Demonstration:\n");
    float small = FLT_MIN;
    printf("FLT_MIN (normalized): %.10e\n", small);
    printf("FLT_MIN / 2 = %.10e\n", small / 2.0f);
    printf("FLT_MIN / 1000 = %.10e\n", small / 1000.0f);
    
    // Special values
    printf("\nSpecial Values:\n");
    float inf = 1.0f / 0.0f;
    float neg_inf = -1.0f / 0.0f;
    float nan = 0.0f / 0.0f;
    printf("Positive infinity: %f\n", inf);
    printf("Negative infinity: %f\n", neg_inf);
    printf("NaN (0/0): %f\n", nan);
    printf("inf + 1: %f\n", inf + 1.0f);
    printf("inf - inf: %f\n", inf - inf);
    
    printf("\nRange of IEEE-754 single precision:\n");
    printf("Maximum value: %.10e\n", FLT_MAX);
    printf("Minimum normalized value: %.10e\n", FLT_MIN);
    printf("Minimum subnormal value: %.10e\n", FLT_MIN / (1 << 23));
}

// Task 6: Normalized vs Denormalized Numbers
void normalized_vs_denormalized() {
    printf("\n=== Normalized vs Denormalized (Subnormal) Numbers ===\n");
    
    printf("Normalized Numbers:\n");
    printf("FLT_MIN (smallest normalized): %.10e\n", FLT_MIN);
    printf("This has an exponent of -126\n");
    printf("Format: 1.mantissa × 2^(-126)\n");
    
    printf("\nDenormalized (Subnormal) Numbers:\n");
    float denorm = FLT_MIN / 2.0f;
    printf("FLT_MIN / 2 = %.10e\n", denorm);
    printf("This has an exponent of 0 in the binary representation\n");
    printf("Format: 0.mantissa × 2^(-126)\n");
    
    printf("\nProgressive Underflow:\n");
    float num = FLT_MIN;
    printf("Starting with FLT_MIN: %.10e\n", num);
    for (int i = 1; i <= 5; i++) {
        num /= 2.0f;
        printf("Divide by 2 (step %d): %.10e\n", i, num);
    }
    
    printf("\nDetailed Analysis:\n");
    union {
        float f;
        unsigned int i;
    } conv;
    
    // Normalized number
    conv.f = FLT_MIN;
    unsigned int exp = (conv.i >> 23) & 0xFF;
    printf("FLT_MIN exponent bits: %u (not zero = normalized)\n", exp);
    
    // Denormalized number
    conv.f = FLT_MIN / 2.0f;
    exp = (conv.i >> 23) & 0xFF;
    printf("FLT_MIN/2 exponent bits: %u (zero = denormalized)\n", exp);
}

void print_menu() {
    printf("\n==========================================\n");
    printf("Floating-Point Number Representation\n");
    printf("==========================================\n");
    printf("1. IEEE-754 Single Precision Conversion\n");
    printf("2. Decimal to Binary Fraction Conversion\n");
    printf("3. Floating-Point Precision Error Demo\n");
    printf("4. Single vs Double Precision Comparison\n");
    printf("5. Overflow and Underflow Demonstration\n");
    printf("6. Normalized vs Denormalized Numbers\n");
    printf("0. Exit\n");
    printf("==========================================\n");
}

int main() {
    int choice;
    float num;
    
    while (1) {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter a decimal number: ");
                scanf("%f", &num);
                ieee754_conversion(num);
                break;
                
            case 2:
                printf("Enter a decimal number (0.x format): ");
                scanf("%f", &num);
                decimal_to_binary_fraction(num);
                break;
                
            case 3:
                precision_error_demo();
                break;
                
            case 4:
                single_vs_double_precision();
                break;
                
            case 5:
                overflow_underflow_demo();
                break;
                
            case 6:
                normalized_vs_denormalized();
                break;
                
            case 0:
                printf("Exiting...\n");
                return 0;
                
            default:
                printf("Invalid choice. Please try again.\n");
        }
        
        printf("\nPress Enter to continue...");
        getchar();
        getchar();
    }
    
    return 0;
}