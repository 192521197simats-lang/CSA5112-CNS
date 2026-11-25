/* EXP 20: ECB/CBC Error Propagation
 * CNS lab solution. Readable, line-by-line C source.
 */
#include <stdio.h>

int main(void)
{
    printf("CBC ciphertext error propagation:\n");
    printf("A bit error in C1 corrupts all of P1 (block cipher output) and flips the matching bit in P2.\n");
    printf("Blocks P3 onward are not affected by a single C1 bit error.\n");
    printf("A source plaintext bit error in P1 changes C1; subsequent CBC ciphertext blocks generally change.\n");
    printf("At the receiver, P1 is corrupted, and later plaintext blocks are also affected through chaining.\n");
    return 0;
}
