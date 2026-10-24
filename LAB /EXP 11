#include <stdio.h>
#include <math.h>

int main() {
    double total_keys = 1.0;
    for (int i = 1; i <= 25; i++) {
        total_keys *= i;
    }

    double power_of_2 = log2(total_keys);

    printf("Total possible keys (25!): %.0f\n", total_keys);
    printf("Approximate power of 2: 2^(%.2f)\n\n", power_of_2);

    double unique_keys = 1.0;
    for (int i = 1; i <= 24; i++) {
        unique_keys *= i;
    }
    double unique_power_of_2 = log2(unique_keys);

    printf("Effectively unique keys (24!): %.0f\n", unique_keys);
    printf("Approximate power of 2: 2^(%.2f)\n", unique_power_of_2);

    return 0;
}
