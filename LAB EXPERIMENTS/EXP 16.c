/* EXP 16: Monoalphabetic Frequency Attack
 * CNS lab solution. Readable, line-by-line C source.
 */
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    char cipher[1000];
    int freq[26]={0}, order[26], count=0;
    const char english[]="ETAOINSHRDLCUMWFGYPBVKJXQZ";
    printf("Substitution ciphertext: ");
    fgets(cipher,sizeof(cipher),stdin);
    for(int i=0;cipher[i];i++) if(isalpha((unsigned char)cipher[i]) ) freq[toupper((unsigned char)cipher[i])-'A']++;
    for(int i=0;i<26;i++) order[i]=i;
    for(int i=0;i<26;i++) for(int j=i+1;j<26;j++)
        if(freq[order[j]]>freq[order[i]]){int t=order[i];order[i]=order[j];order[j]=t;}
    char map[26];
    for(int i=0;i<26;i++) map[order[i]]=english[i];
    printf("Frequency-based candidate: ");
    for(int i=0;cipher[i];i++) {
        char c=cipher[i];
        if(isalpha((unsigned char)c)) putchar(map[toupper((unsigned char)c)-'A']);
        else putchar(c);
    }
    printf("\nNote: frequency substitution is only a rough heuristic; word patterns are needed for accuracy.\n");
    return 0;
}
