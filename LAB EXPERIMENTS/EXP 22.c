#include <stdio.h>
#include <string.h>
/* Toy CBC demonstration using XOR as a reversible block transform. It is NOT S-DES. */
int main(){unsigned char iv=0xAA,key=0x5D,p[]={0x00,0x01,0x12,0x23},c[4],d[4],prev=iv;for(int i=0;i<4;i++){c[i]=p[i]^prev^key;prev=c[i];}printf("Toy CBC ciphertext: ");for(int i=0;i<4;i++)printf("%02X ",c[i]);prev=iv;for(int i=0;i<4;i++){d[i]=c[i]^prev^key;prev=c[i];}printf("\nRecovered: ");for(int i=0;i<4;i++)printf("%02X ",d[i]);puts("\nFor actual S-DES test vectors, implement S-DES block encryption and use it in CBC rather than this toy XOR transform.");return 0;}
