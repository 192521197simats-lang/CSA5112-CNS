#include <stdio.h>
long long egcd(long long a,long long b,long long*x,long long*y){if(!b){*x=1;*y=0;return a;}long long x1,y1,g=egcd(b,a%b,&x1,&y1);*x=y1;*y=x1-(a/b)*y1;return g;}
int main(){long long n=3599,e=31,p=59,q=61,phi=(p-1)*(q-1),x,y;egcd(e,phi,&x,&y);long long d=(x%phi+phi)%phi;printf("n=%lld = %lld*%lld; phi=%lld; private d=%lld\n",n,p,q,phi,d);return 0;}
