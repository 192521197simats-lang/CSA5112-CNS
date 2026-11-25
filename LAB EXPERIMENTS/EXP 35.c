#include <stdio.h>
#include <ctype.h>
int main(){char s[500];printf("Plaintext: ");fgets(s,500,stdin);printf("Enter numeric key stream shifts, one per alphabetic character (end with -1):\n");int key[500],n=0;while(n<499&&scanf("%d",&key[n])==1&&key[n]!=-1)n++;int j=0;for(int i=0;s[i];i++)if(isalpha(s[i])){if(j>=n){puts("Not enough key numbers.");return 1;}int v=(tolower(s[i])-'a'+key[j]%26)%26;s[i]=isupper(s[i])?v+'A':v+'a';j++;}printf("Ciphertext: %s\n",s);return 0;}
