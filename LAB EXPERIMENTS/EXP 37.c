#include <stdio.h>
#include <ctype.h>
int main(){char s[1000];int top;printf("Ciphertext: ");fgets(s,1000,stdin);printf("Top candidate count (1-26): ");scanf("%d",&top);if(top<1)top=1;if(top>26)top=26;puts("Simple automatic candidates: shift guesses; full monoalphabetic substitution cracking needs word-pattern/quadgram scoring.");for(int k=0;k<top;k++){printf("Guess %d: ",k+1);for(int i=0;s[i];i++)if(isalpha(s[i]))putchar((toupper(s[i])-'A'-k+26)%26+'A');else putchar(s[i]);puts("");}return 0;}
