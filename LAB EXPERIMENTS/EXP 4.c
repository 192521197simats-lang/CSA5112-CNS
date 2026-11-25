#include <stdio.h>
#include <ctype.h>
int main(){char s[500],key[100];printf("Plaintext: ");fgets(s,500,stdin);printf("Key: ");fgets(key,100,stdin);int j=0;for(int i=0;s[i];i++)if(isalpha(s[i])){int shift=tolower(key[j% (int)(__builtin_strlen(key)-1)])-'a';if(isupper(s[i]))s[i]=(s[i]-'A'+shift)%26+'A';else s[i]=(s[i]-'a'+shift)%26+'a';j++;}printf("Ciphertext: %s",s);return 0;}
