#include <stdio.h>
#include <string.h>
int main(){char s[100];printf("Enter plaintext: ");fgets(s,100,stdin);int n=strlen(s);if(n&& s[n-1]=='\n')s[--n]=0;int block=8,pad=block-(n%block);if(pad==0)pad=block;printf("Original bytes=%d; padding bytes=%d (toy byte version of 1-bit then zeros)\n",n,pad);puts("Padding every message, even when aligned, ensures padding can be removed unambiguously and distinguishes an exactly full final block from no padding.");return 0;}
