#include <stdio.h>
#include <ctype.h>
#include <string.h>
int inv(int x){for(int i=1;i<26;i++)if(x*i%26==1)return i;return -1;}
int main(){char s[500],p[500];int K[2][2]={{9,4},{5,7}},det=K[0][0]*K[1][1]-K[0][1]*K[1][0],di=inv((det%26+26)%26);printf("Plaintext: ");fgets(s,500,stdin);int n=0;for(int i=0;s[i];i++)if(isalpha(s[i]))p[n++]=tolower(s[i]);if(n%2)p[n++]='x';p[n]=0;char c[500];for(int i=0;i<n;i+=2){int x=p[i]-'a',y=p[i+1]-'a';c[i]=(9*x+4*y)%26+'a';c[i+1]=(5*x+7*y)%26+'a';}c[n]=0;printf("Cipher: %s\n",c);if(di<0){puts("Key matrix has no inverse mod 26");return 0;}int invK[2][2]={ {(K[1][1]*di)%26,(-K[0][1]*di%26+26)%26},{(-K[1][0]*di%26+26)%26,(K[0][0]*di)%26}};printf("Inverse key modulo 26: [%d %d; %d %d]\n",invK[0][0],invK[0][1],invK[1][0],invK[1][1]);for(int i=0;i<n;i+=2){int x=c[i]-'a',y=c[i+1]-'a';p[i]=(invK[0][0]*x+invK[0][1]*y)%26+'a';p[i+1]=(invK[1][0]*x+invK[1][1]*y)%26+'a';}p[n]=0;printf("Recovered letters (padding x may remain): %s\n",p);return 0;}
