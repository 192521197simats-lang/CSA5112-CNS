/* EXP 15: Additive Cipher Frequency Attack
 * CNS lab solution. Readable, line-by-line C source.
 */
#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char cipher[1000];
    printf("Additive cipher ciphertext: ");
    fgets(cipher,sizeof(cipher),stdin);
    printf("All 26 possible shifts (plaintext candidates):\n");
    for(int k=0;k<26;k++) {
        printf("Shift %2d: ",k);
        for(int i=0;cipher[i];i++) {
            char c=cipher[i];
            if(isalpha((unsigned char)c)) putchar('A'+(toupper((unsigned char)c)-'A'-k+26)%26);
            else putchar(c);
        }
        putchar('\n');
    }
    return 0;
}
