/* EXP 24: RSA Private Key
 * CNS lab solution. Readable, line-by-line C source.
 */
#include <stdio.h>

int gcd(int a,int b){while(b){int t=b;b=a%b;a=t;}return a;}
int main(void)
{
    int n=3599,e=31,p=0,q=0;
    for(int i=2;i*i<=n;i++) if(n%i==0){p=i;q=n/i;break;}
    if(!p){printf("Could not factor n.\n");return 1;}
    int phi=(p-1)*(q-1),d=1;
    while((d*e)%phi!=1)d++;
    printf("n=%d = %d * %d\nphi(n)=%d\ne=%d\nd=%d (inverse of e mod phi)\n",n,p,q,phi,e,d);
    return 0;
}
