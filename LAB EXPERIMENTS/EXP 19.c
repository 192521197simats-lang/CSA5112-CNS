#include <stdio.h>
#include <string.h>
/* CBC mode illustration with a toy XOR block cipher; replace toy_enc with a vetted 3DES library call for real cryptography. */
void toy_enc(unsigned char b[8],unsigned char key[8]){for(int i=0;i<8;i++)b[i]^=key[i];}
int main(){unsigned char key[8]="toy-key",iv[8]="init-vec",block[8],prev[8];char msg[200];printf("Message (max 7 chars per block demo): ");fgets(msg,200,stdin);strncpy((char*)block,msg,8);memcpy(prev,iv,8);for(int i=0;i<8;i++)block[i]^=prev[i];toy_enc(block,key);printf("Toy CBC ciphertext block (hex): ");for(int i=0;i<8;i++)printf("%02X",block[i]);puts("");puts("Security: choose 3DES (or preferably AES today). Performance: 3DES is slower than DES; modern AES hardware is usually preferable.");return 0;}
