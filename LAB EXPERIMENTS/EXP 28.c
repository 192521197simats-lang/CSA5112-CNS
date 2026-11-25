/* EXP 28: Diffie-Hellman
 * CNS lab solution. Readable, line-by-line C source.
 */
#include <stdio.h>

long long modpow(long long a,long long e,long long q){
    long long r=1; a%=q;
    while(e){if(e&1)r=r*a%q;a=a*a%q;e>>=1;}
    return r;
}
int main(void)
{
    long long q=23,a=5,x=6,y=15;
    long long A=modpow(a,x,q),B=modpow(a,y,q);
    long long ka=modpow(B,x,q),kb=modpow(A,y,q);
    printf("Public q=%lld, base a=%lld\nAlice secret x=%lld, public A=%lld\nBob secret y=%lld, public B=%lld\n",q,a,x,A,y,B);
    printf("Alice shared key=%lld\nBob shared key=%lld\n",ka,kb);
    printf("Sending x^a instead of a^x does not create the standard DH exchange and may reveal/enable attacks.\n");
    return 0;
}
