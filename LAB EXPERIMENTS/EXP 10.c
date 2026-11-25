/* EXP 10: Playfair Encryption Using Given Matrix
 * CNS lab solution. Readable, line-by-line C source.
 */
#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char m[5][5] = {
        {'M','F','H','I','K'},
        {'U','N','O','P','Q'},
        {'Z','V','W','X','Y'},
        {'E','L','A','R','G'},
        {'D','S','T','B','C'}
    };
    char text[500], clean[500], out[600];
    int n=0, k=0;
    printf("Message: ");
    fgets(text,sizeof(text),stdin);
    for(int i=0;text[i];i++) if(isalpha((unsigned char)text[i])) {
        char c=toupper((unsigned char)text[i]); clean[n++]=c=='J'?'I':c;
    }
    for(int i=0;i<n;) {
        char a=clean[i++], b=(i<n)?clean[i++]:'X';
        if(a==b) { b='X'; i--; }
        int r1=-1,c1=-1,r2=-1,c2=-1;
        for(int r=0;r<5;r++) for(int c=0;c<5;c++) {
            if(m[r][c]==a){r1=r;c1=c;}
            if(m[r][c]==b){r2=r;c2=c;}
        }
        if(r1==r2){out[k++]=m[r1][(c1+1)%5];out[k++]=m[r2][(c2+1)%5];}
        else if(c1==c2){out[k++]=m[(r1+1)%5][c1];out[k++]=m[(r2+1)%5][c2];}
        else {out[k++]=m[r1][c2];out[k++]=m[r2][c1];}
    }
    out[k]='\0'; printf("Ciphertext: %s\n",out); return 0;
}
