#include <stdio.h>
#include <stdint.h>
uint64_t shift64(uint64_t x){return (x<<1)^((x>>63)?0x1B:0);}
void shift128(unsigned char x[16]){int carry=x[0]>>7;for(int i=0;i<16;i++){int next=(i<15?x[i+1]>>7:0);x[i]=(x[i]<<1)|next;}if(carry)x[15]^=0x87;}
int main(){puts("CMAC reduction constants: 64-bit block Rb=0x1B; 128-bit block Rb=0x87.");uint64_t l=0x8000000000000000ULL;printf("Example 64-bit doubling: %016llX -> %016llX\n",(unsigned long long)l,(unsigned long long)shift64(l));puts("Left shift multiplies by x in GF(2); XOR Rb reduces modulo the irreducible polynomial when the high bit was set.");return 0;}
