/* EXP 23: S-DES CTR Exercise
 * CNS lab solution. Readable, line-by-line C source.
 */
#include <stdio.h>

int main(void)
{
    printf("S-DES CTR test-vector task:\n");
    printf("Counter begins at 00000000. For each block compute S_i=E_K(counter_i),\n");
    printf("then C_i=P_i XOR S_i and increment the counter modulo 256.\n");
    printf("CTR decryption uses the same XOR operation with the generated keystream.\n");
    printf("This file is a concise algorithm guide; a complete S-DES block implementation is needed for vector validation.\n");
    return 0;
}
