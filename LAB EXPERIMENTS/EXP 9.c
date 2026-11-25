#include <stdio.h>
#include <ctype.h>
#include <string.h>
void mk(char *k,char m[5][5]){int v[26]={0},n=0;char a[25];for(int i=0;k[i];i++){char c=toupper(k[i]);if(c=='J')c='I';if(c>='A'&&c<='Z'&&!v[c-'A'])v[c-'A']=1,a[n++]=c;}for(char c='A';c<='Z';c++)if(c!='J'&&!v[c-'A'])a[n++]=c;for(int i=0;i<25;i++)m[i/5][i%5]=a[i];}
void find(char m[5][5],char c,int *r,int *col){if(c=='J')c='I';for(int i=0;i<5;i++)for(int j=0;j<5;j++)if(m[i][j]==c)*r=i,*col=j;}
int main(){char key[100],ct[500];char m[5][5];printf("Playfair key for PT-109 ciphertext (key not supplied in question): ");fgets(key,100,stdin);printf("Ciphertext: ");fgets(ct,500,stdin);mk(key,m);char out[500];int z=0;for(int i=0;ct[i];){if(!isalpha(ct[i])){i++;continue;}char a=toupper(ct[i++]),b='X';while(ct[i]&&!isalpha(ct[i]))i++;if(ct[i])b=toupper(ct[i++]);int r1,c1,r2,c2;find(m,a,&r1,&c1);find(m,b,&r2,&c2);if(r1==r2)out[z++]=m[r1][(c1+4)%5],out[z++]=m[r2][(c2+4)%5];else if(c1==c2)out[z++]=m[(r1+4)%5][c1],out[z++]=m[(r2+4)%5][c2];else out[z++]=m[r1][c2],out[z++]=m[r2][c1];}out[z]=0;printf("Decoded (remove filler X manually): %s\n",out);return 0;}
