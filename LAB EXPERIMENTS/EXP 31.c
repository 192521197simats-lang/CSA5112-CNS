/* EXP 31: CMAC Subkey Generation
 * CNS lab solution. Readable, line-by-line C source.
 */
#include <stdio.h>
#include <stdint.h>

void shift_left(uint8_t *b,int n){
    int carry=0;
    for(int i=n-1;i>=0;i--){int next=(b[i]>>7)&1;b[i]=(uint8_t)((b[i]<<1)|carry);carry=next;}
}
int main(void)
{
    printf("CMAC reduction constants: 64-bit block: Rb=0x1B; 128-bit block: Rb=0x87.\n");
    printf("The shift implements multiplication by x in GF(2^n). If the top bit was 1,\n");
    printf("XOR Rb to reduce modulo the field polynomial.\n");
    return 0;
}
