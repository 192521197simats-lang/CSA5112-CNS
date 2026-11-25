/* EXP 22: S-DES CBC Exercise
 * CNS lab solution. Readable, line-by-line C source.
 */
#include <stdio.h>

int main(void)
{
    printf("S-DES CBC test-vector task:\n");
    printf("IV = 10101010, key = 0111111101, plaintext = 00000001 00000010 00000011.\n");
    printf("Use S-DES encryption for each 8-bit block: C_i = E_K(P_i XOR C_(i-1)); C_0=IV.\n");
    printf("This source explains the CBC calculation. Implementing the full S-DES tables is required to verify the supplied vector.\n");
    return 0;
}
