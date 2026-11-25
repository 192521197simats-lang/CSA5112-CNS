/* EXP 11: Playfair Key Space
 * CNS lab solution. Readable, line-by-line C source.
 */
#include <stdio.h>
#include <math.h>

int main(void)
{
    long long total = 1;
    for (int i = 1; i <= 25; i++) total *= i;
    printf("Raw Playfair key count: 25! = approximately 2^%.2f\n", log2((double)total));
    printf("A matrix has 25! arrangements. Equivalent keys may differ by rotations/representations,\n");
    printf("so effective key counts depend on the equivalence definition used in the question.\n");
    return 0;
}
