/* EXP 21: ECB CBC CFB Padding
 * CNS lab solution. Readable, line-by-line C source.
 */
#include <stdio.h>
#include <string.h>

int main(void)
{
    char bits[300], padded[400];
    int n, k=0;
    printf("Enter plaintext bits: ");
    scanf("%299s",bits);
    n=(int)strlen(bits);
    for(int i=0;i<n;i++) padded[k++]=bits[i];
    padded[k++]='1';
    while(k%8) padded[k++]='0';
    padded[k]='\0';
    printf("Padded bits (8-bit blocks): %s\n",padded);
    printf("A full extra padding block helps distinguish an unpadded message from one ending in padding-like bits.\n");
    return 0;
}
