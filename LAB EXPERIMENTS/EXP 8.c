#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main(){char key[100],s[500],cipher[26];int seen[26]={0},n=0;printf("Keyword: ");fgets(key,100,stdin);for(int i=0;key[i];i++){char c=toupper(key[i]);if(c>='A'&&c<='Z'&&!seen[c-'A'])cipher[n++]=c,seen[c-'A']=1;}for(char c='A';c<='Z';c++)if(!seen[c-'A'])cipher[n++]=c;printf("Plaintext: ");fgets(s,500,stdin);for(int i=0;s[i];i++)if(isalpha(s[i])){int u=isupper(s[i]);char c=cipher[tolower(s[i])-'a'];s[i]=u?c:tolower(c);}printf("Ciphertext: %s\nCipher alphabet: %.*s\n",s,26,cipher);return 0;}
