/* EXP 38: Hill Cipher Attack (Repeat)
 * CNS lab solution. Readable, line-by-line C source.
 */
#include <stdio.h>

int main(void)
{
    printf("Hill cipher known-plaintext attack demonstration.\n");
    printf("For 2x2 Hill, choose two independent plaintext vectors P1,P2 and matching C1,C2.\n");
    printf("Arrange P=[P1 P2], C=[C1 C2]. If det(P) has an inverse modulo 26,\n");
    printf("the key matrix is K = C * inverse(P) (mod 26).\n");
    printf("This program is a calculation guide; enter pairs and perform modular matrix operations.\n");
    return 0;
}
