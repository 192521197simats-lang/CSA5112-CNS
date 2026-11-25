#include <stdio.h>
#include <ctype.h>
int main(){char s[1000],map[26];for(int i=0;i<26;i++)map[i]='?';puts("Enter ciphertext (substitution cipher). This simple helper lets you fill guessed mappings.");fgets(s,sizeof s,stdin);printf("Mapping ciphertext letters to plaintext (e.g. A E): enter pairs, 0 to finish\n");char c,p;while(scanf(" %c %c",&c,&p)==2){if(c=='0')break;map[toupper(c)-'A']=tolower(p);}for(int i=0;s[i];i++){if(isupper(s[i]))s[i]=toupper(map[s[i]-'A']);else if(islower(s[i]))s[i]=map[s[i]-'a'];}printf("Decoded guess: %s",s);return 0;}
