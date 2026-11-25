/* EXP 35: One-Time Pad Vigenere (Repeat)
 * CNS lab solution. Readable, line-by-line C source.
 */
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    char msg[]="send more money";
    int key[]={9,0,1,7,23,15,21,14,11,11,2,8,9};
    char out[100]; int j=0;
    for(int i=0;msg[i];i++) {
        if(isalpha((unsigned char)msg[i])) {
            int p=tolower((unsigned char)msg[i])-'a';
            out[j]=(char)('a'+(p+key[i < 13 ? i : 12])%26); j++;
        } else out[j++]=msg[i];
    }
    out[j]='\0';
    printf("Plaintext: %s\nCiphertext: %s\n",msg,out);
    return 0;
}
