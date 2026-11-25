/* EXP 26: RSA Key Reuse Security
 * CNS lab solution. Readable, line-by-line C source.
 */
#include <stdio.h>

int main(void)
{
    printf("Changing RSA public exponent while keeping the same modulus is unsafe after private-key leakage.\n");
    printf("The leaked d is related to the same p, q, and phi(n); choosing a new exponent does not rotate the modulus.\n");
    printf("Generate a new RSA key pair with a fresh modulus and revoke the compromised key.\n");
    return 0;
}
