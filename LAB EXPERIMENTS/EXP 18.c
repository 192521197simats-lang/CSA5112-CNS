/* EXP 18: DES Key Generation Structure
 * CNS lab solution. Readable, line-by-line C source.
 */
#include <stdio.h>

int main(void)
{
    printf("DES PC-1 splits the 56 effective key bits into C0 and D0, each 28 bits.\n");
    printf("Each round rotates both halves; PC-2 selects 24 bits from C and 24 from D.\n");
    printf("The halves are disjoint because C and D contain separate key-bit subsets.\n");
    printf("This is a structural property of the DES key schedule, not a separate key generator.\n");
    return 0;
}
