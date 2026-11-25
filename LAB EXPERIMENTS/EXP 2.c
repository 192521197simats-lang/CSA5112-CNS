#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main(){char s[500],key[27];int seen[26]={0};printf("Enter 26-letter substitution alphabet: ");scanf("%26s",key);if(strlen(key)!=26){puts("Key must contain 26 letters.");return 1;}for(int i=0;i<26;i++){key[i]=toupper(key[i]);if(key[i]<'A'||key[i]>'Z'||seen[key[i]-'A']){puts("Invalid key: letters must be unique.");return 1;}seen[key[i]-'A']=1;}getchar();printf("Plaintext: ");fgets(s,sizeof s,stdin);for(int i=0;s[i];i++)if(isalpha(s[i])){int upper=isupper(s[i]);s[i]=key[tolower(s[i])-'a'];if(!upper)s[i]=tolower(s[i]);}printf("Ciphertext: %s",s);return 0;}
