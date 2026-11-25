#include <stdio.h>
/* Toy CTR demo using XOR with counter/key; illustrative only, not S-DES. */
int main(){unsigned char p[]={0,1,2,4},key=0x5D;printf("Toy CTR ciphertext: ");for(int i=0;i<4;i++){unsigned char ctr=i,stream=ctr^key;printf("%02X ",p[i]^stream);}puts("\nCTR decryption repeats XOR with the same counter stream. Use a real block cipher for security.");return 0;}
