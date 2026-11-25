/* EXP 9: Playfair PT-109 Decryption
 * CNS lab solution. Readable, line-by-line C source.
 */
#include <stdio.h>
#include <ctype.h>

void matrix(char *key, char m[5][5]) {
    int used[26]={0}, k=0; used[9]=1;
    for (int pass=0; pass<2; pass++) {
        char *s=pass ? "ABCDEFGHIJKLMNOPQRSTUVWXYZ" : key;
        for (int i=0; s[i]; i++) {
            char c=toupper((unsigned char)s[i]); if (!isalpha((unsigned char)c)) continue;
            if(c=='J') c='I';
            if(!used[c-'A']) { used[c-'A']=1; m[k/5][k%5]=c; k++; }
        }
    }
}
void find(char m[5][5], char c, int *r, int *col) {
    if(c=='J') c='I';
    for(*r=0; *r<5; (*r)++) for(*col=0; *col<5; (*col)++)
        if(m[*r][*col]==c) return;
}
int main(void) {
    char key[100], text[500]; char m[5][5];
    printf("Playfair keyword: "); scanf("%99s", key);
    printf("PT-109 ciphertext (spaces allowed): "); scanf(" %499[^\n]", text);
    matrix(key,m);
    for(int i=0;text[i];i++) if(isalpha((unsigned char)text[i])) text[i]=toupper((unsigned char)text[i]);
    printf("Decrypted digraphs: ");
    for(int i=0;text[i] && text[i+1];i+=2) {
        int r1,c1,r2,c2; find(m,text[i],&r1,&c1); find(m,text[i+1],&r2,&c2);
        if(r1==r2) { putchar(m[r1][(c1+4)%5]); putchar(m[r2][(c2+4)%5]); }
        else if(c1==c2) { putchar(m[(r1+4)%5][c1]); putchar(m[(r2+4)%5][c2]); }
        else { putchar(m[r1][c2]); putchar(m[r2][c1]); }
    }
    putchar('\n'); return 0;
}
