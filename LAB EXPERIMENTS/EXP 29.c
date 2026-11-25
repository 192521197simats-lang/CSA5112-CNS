/* EXP 29: SHA-3 Capacity Lane Exercise
 * CNS lab solution. Readable, line-by-line C source.
 */
#include <stdio.h>

int main(void)
{
    printf("SHA-3 lane propagation exercise (permutation ignored).\n");
    printf("For SHA3-256, the state is 1600 bits; capacity is 512 bits (8 lanes of 64 bits).\n");
    printf("If all capacity lanes start zero and each message lane is nonzero, XORing the message into the rate\n");
    printf("does not immediately change capacity lanes. With permutation ignored, they remain zero indefinitely.\n");
    printf("In real SHA-3, the permutation mixes rate and capacity lanes.\n");
    return 0;
}
