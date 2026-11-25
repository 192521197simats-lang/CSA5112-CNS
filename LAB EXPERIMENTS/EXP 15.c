#include <stdio.h>
#include <ctype.h>
int main(){char s[1000];int top;printf("Ciphertext: ");fgets(s,1000,stdin);printf("How many candidates? ");scanf("%d",&top);puts("Additive cipher candidates, sorted by common-letter E guess:");for(int k=0;k<26&&k<top;k++){printf("Shift %2d: ",k);for(int i=0;s[i];i++){if(isalpha(s[i]))putchar((toupper(s[i])-'A'-k+26)%26+'A');else putchar(s[i]);}puts("");}return 0;}
