/* EXP 27: RSA Letterwise Attack
 * CNS lab solution. Readable, line-by-line C source.
 */
#include <stdio.h>

int main(void)
{
    printf("Textbook RSA encrypting each letter separately is insecure.\n");
    printf("It is deterministic: each letter always produces the same ciphertext block.\n");
    printf("An attacker can encrypt all 26 possible letters with the public key and build a lookup table,\n");
    printf("then map ciphertext blocks back to letters. Use randomized padding (e.g., OAEP) instead.\n");
    return 0;
}
