/* EXP 30: CBC-MAC Attack
 * CNS lab solution. Readable, line-by-line C source.
 */
#include <stdio.h>

int main(void)
{
    printf("CBC-MAC extension/forgery demonstration (single-block MAC T=E_K(X)).\n");
    printf("For the two-block message X || (X XOR T), CBC-MAC's second input to E_K becomes T XOR (X XOR T)=X.\n");
    printf("The final MAC is therefore E_K(X)=T, reusing the one-block tag.\n");
    printf("CBC-MAC should be used with fixed-length messages or a secure variant such as CMAC.\n");
    return 0;
}
