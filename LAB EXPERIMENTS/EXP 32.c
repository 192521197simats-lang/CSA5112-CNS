/* EXP 32: DSA Signature Randomness
 * CNS lab solution. Readable, line-by-line C source.
 */
#include <stdio.h>

int main(void)
{
    printf("DSA uses a fresh secret nonce k for each signature.\n");
    printf("The signature includes r and s; a different k normally produces a different signature for the same message.\n");
    printf("If k is reused or exposed, the private key may be recovered. Use a secure nonce generator.\n");
    printf("This program summarizes the implication; it is not a full DSA implementation.\n");
    return 0;
}
