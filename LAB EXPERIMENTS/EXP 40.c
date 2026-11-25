#include <stdio.h>
#include <ctype.h>
int main(){char s[1000];int top=10;printf("Ciphertext: ");fgets(s,1000,stdin);printf("Top possible plaintexts (1-26): ");scanf("%d",&top);if(top<1)top=1;if(top>26)top=26;puts("Candidate ranking is a basic shift-based heuristic only; complete substitution cracking requires language scoring and search.");for(int k=0;k<top;k++){printf("Candidate %d (shift %d): ",k+1,k);for(int i=0;s[i];i++)if(isalpha(s[i]))putchar((toupper(s[i])-'A'-k+26)%26+'A');else putchar(s[i]);puts("");}return 0;}
