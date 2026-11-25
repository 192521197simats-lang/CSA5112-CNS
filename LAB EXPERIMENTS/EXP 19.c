/* EXP 19: Triple DES CBC Concept
 * CNS lab solution. Readable, line-by-line C source.
 */
#include <stdio.h>
#include <stdint.h>

uint8_t toy_encrypt(uint8_t x, uint8_t k){ return (uint8_t)((x+k)^0xA5); }
int main(void)
{
    uint8_t iv=0x5A, key=0x13, p[]={0x41,0x42,0x43}, c[3], prev=iv;
    printf("Educational CBC demo (toy block transform; not real 3DES).\n");
    for(int i=0;i<3;i++){c[i]=toy_encrypt(p[i]^prev,key);prev=c[i];}
    printf("Cipher blocks: ");
    for(int i=0;i<3;i++)printf("%02X ",c[i]);
    printf("\nFor security use a vetted library and modern authenticated encryption.\n");
    return 0;
}
