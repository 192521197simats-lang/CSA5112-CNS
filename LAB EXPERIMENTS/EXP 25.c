/* EXP 25: RSA Common Factor Attack
 * CNS lab solution. Readable, line-by-line C source.
 */
#include <stdio.h>

int gcd(int a,int b){while(b){int t=b;b=a%b;a=t;}return a;}
int main(void)
{
    int n=77, block=14;
    int g=gcd(n,block);
    printf("Example n=%d and plaintext block=%d\n",n,block);
    printf("gcd(block,n)=%d\n",g);
    if(g>1 && g<n) printf("This reveals a nontrivial factor of n: %d and %d\n",g,n/g);
    else printf("This block does not reveal a nontrivial factor in this example.\n");
    return 0;
}
