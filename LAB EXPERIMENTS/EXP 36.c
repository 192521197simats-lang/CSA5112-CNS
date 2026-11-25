#include <stdio.h>
#include <ctype.h>
int gcd(int a,int b){while(b){int t=a%b;a=b;b=t;}return a;}
int main(){char s[500];int a,b;printf("Plaintext: ");fgets(s,500,stdin);printf("a b: ");scanf("%d%d",&a,&b);if(gcd((a%26+26)%26,26)!=1){puts("a must be coprime to 26; valid values: 1,3,5,7,9,11,15,17,19,21,23,25");return 0;}for(int i=0;s[i];i++)if(isalpha(s[i])){int x=(tolower(s[i])-'a'),y=(a*x+b)%26;s[i]=isupper(s[i])?y+'A':y+'a';}printf("Affine ciphertext: %s\n",s);puts("b has no restriction other than modulo 26 (0..25).");return 0;}
