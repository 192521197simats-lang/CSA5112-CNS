#include <stdio.h>
#include <string.h>
#include <ctype.h>
void build(char *key,char m[5][5]){int seen[26]={0},n=0;char a[26];for(int i=0;key[i];i++){char c=toupper(key[i]);if(c=='J')c='I';if(c>='A'&&c<='Z'&&!seen[c-'A'])seen[c-'A']=1,a[n++]=c;}for(char c='A';c<='Z';c++){if(c=='J')continue;if(!seen[c-'A'])a[n++]=c;}for(int i=0;i<25;i++)m[i/5][i%5]=a[i];}
void pos(char m[5][5],char c,int *r,int *col){if(c=='J')c='I';for(int i=0;i<5;i++)for(int j=0;j<5;j++)if(m[i][j]==c)*r=i,*col=j;}
int main(){char key[100],s[500],p[500],a,b;char m[5][5];printf("Keyword: ");fgets(key,100,stdin);build(key,m);printf("Plaintext: ");fgets(s,500,stdin);int n=0;for(int i=0;s[i];i++)if(isalpha(s[i]))p[n++]=toupper(s[i]=='J'?'I':s[i]);p[n]=0;char out[600];int z=0;for(int i=0;i<n;i+=2){a=p[i];b=(i+1<n)?p[i+1]:'X';if(a==b)b='X';int r1,c1,r2,c2;pos(m,a,&r1,&c1);pos(m,b,&r2,&c2);if(r1==r2)out[z++]=m[r1][(c1+1)%5],out[z++]=m[r2][(c2+1)%5];else if(c1==c2)out[z++]=m[(r1+1)%5][c1],out[z++]=m[(r2+1)%5][c2];else out[z++]=m[r1][c2],out[z++]=m[r2][c1];}out[z]=0;printf("Ciphertext: %s\nMatrix:\n",out);for(int i=0;i<5;i++){for(int j=0;j<5;j++)printf("%c ",m[i][j]);puts("");}return 0;}
