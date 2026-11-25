#include <stdio.h>
#include <ctype.h>
int main(){char s[1000];int top;printf("Ciphertext: ");fgets(s,1000,stdin);printf("Top guesses: ");scanf("%d",&top);if(top<1)top=1;if(top>26)top=26;for(int k=0;k<top;k++){printf("Shift %d: ",k);for(int i=0;s[i];i++)if(isalpha(s[i]))putchar((toupper(s[i])-'A'-k+26)%26+'A');else putchar(s[i]);}return 0;}
