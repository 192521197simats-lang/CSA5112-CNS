/* EXP 12: Hill Cipher 2x2
 * CNS lab solution. Readable, line-by-line C source.
 */
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int mod26(int x){x%=26; return x<0?x+26:x;}
int invmod(int x){for(int i=1;i<26;i++) if((x*i)%26==1)return i; return -1;}
int main(void)
{
    int K[2][2]={{9,4},{5,7}};
    int det=mod26(K[0][0]*K[1][1]-K[0][1]*K[1][0]);
    int inv=invmod(det), D[2][2];
    if(inv<0){puts("Key matrix is not invertible modulo 26.");return 1;}
    D[0][0]=mod26(inv*K[1][1]); D[0][1]=mod26(-inv*K[0][1]);
    D[1][0]=mod26(-inv*K[1][0]); D[1][1]=mod26(inv*K[0][0]);
    char msg[]="meet me at the usual place at ten rather than eight oclock";
    char p[200]; int n=0;
    for(int i=0;msg[i];i++) if(isalpha((unsigned char)msg[i])) p[n++]=tolower((unsigned char)msg[i]);
    if(n%2)p[n++]='x';
    printf("Plaintext letters: %s\n",p);
    printf("Ciphertext: ");
    for(int i=0;i<n;i+=2){int a=p[i]-'a',b=p[i+1]-'a';putchar('a'+mod26(K[0][0]*a+K[0][1]*b));putchar('a'+mod26(K[1][0]*a+K[1][1]*b));}
    printf("\nInverse key matrix modulo 26: [%d %d; %d %d]\n",D[0][0],D[0][1],D[1][0],D[1][1]);
    return 0;
}
