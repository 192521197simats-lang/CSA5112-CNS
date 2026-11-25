/* EXP 17: DES Decryption Key Schedule
 * CNS lab solution. Readable, line-by-line C source.
 */
#include <stdio.h>

int main(void)
{
    int shifts[16]={1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1};
    printf("DES decryption uses encryption round keys in reverse order: K16, K15, ..., K1.\n");
    printf("The key schedule itself can be generated normally, then consume the subkeys backwards.\n");
    printf("Round shift schedule: ");
    for(int i=0;i<16;i++) printf("%d ",shifts[i]);
    printf("\n");
    return 0;
}
