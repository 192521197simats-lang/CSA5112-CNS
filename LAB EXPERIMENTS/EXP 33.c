/* EXP 33: DES Implementation Overview
 * CNS lab solution. Readable, line-by-line C source.
 */
#include <stdio.h>
#include <stdint.h>

int main(void)
{
    printf("DES overview: 64-bit input block, 56-bit effective key, 16 Feistel rounds.\n");
    printf("Each round uses expansion, XOR with a 48-bit subkey, S-box substitution and permutation.\n");
    printf("DES is obsolete; use AES or a modern authenticated cipher for real protection.\n");
    printf("This file is an algorithm summary rather than a full DES implementation.\n");
    return 0;
}
