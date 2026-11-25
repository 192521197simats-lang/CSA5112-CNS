#include <stdio.h>
long long gcd(long long a,long long b){while(b){long long t=a%b;a=b;b=t;}return a;}
int main(){long long n,m;printf("RSA modulus n and plaintext block m: ");scanf("%lld%lld",&n,&m);long long g=gcd(n,m);printf("gcd(m,n)=%lld\n",g);if(g>1&&g<n)printf("This reveals a nontrivial factor of n: %lld, and the other factor is %lld. RSA modulus can be factored.\n",g,n/g);else puts("No nontrivial common factor revealed by this block.");return 0;}
