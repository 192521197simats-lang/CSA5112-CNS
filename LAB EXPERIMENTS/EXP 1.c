#include <stdio.h>
#include <ctype.h>
int main(){char s[500];int k;printf("Plaintext: ");fgets(s,sizeof s,stdin);printf("Shift (1-25): ");scanf("%d",&k);k=(k%26+26)%26;for(int i=0;s[i];i++){if(isupper(s[i]))s[i]=(s[i]-'A'+k)%26+'A';else if(islower(s[i]))s[i]=(s[i]-'a'+k)%26+'a';}printf("Ciphertext: %s",s);return 0;}
