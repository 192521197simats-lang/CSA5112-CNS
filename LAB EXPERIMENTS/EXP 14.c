#include <stdio.h>
#include <ctype.h>
int main(){char s[300];int k[]={9,0,1,7,23,15,21,14,11,11,2,8,9},n=0;printf("Plaintext: ");fgets(s,300,stdin);for(int i=0;s[i];i++)if(isalpha(s[i])){int x=tolower(s[i])-'a';s[i]=(x+k[n%13])%26+'A';n++;}printf("Ciphertext: %s\n",s);puts("For part (b), a key stream to turn this ciphertext into CASHNOTNEEDED is computed as (cipher-letter - target-letter) mod 26.");return 0;}
