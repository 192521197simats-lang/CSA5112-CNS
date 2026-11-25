#include <stdio.h>
long long modpow(long long a,long long e,long long n){long long r=1;while(e){if(e&1)r=r*a%n;a=a*a%n;e>>=1;}return r;}
int main(){long long e,n;printf("Public e and n: ");scanf("%lld%lld",&e,&n);puts("RSA-encrypted alphabet symbols (A=0..Z=25):");for(int m=0;m<26;m++)printf("%c -> %lld\n",'A'+m,modpow(m,e,n));puts("Attack: try all 26 possible plaintext letters and match ciphertext values (deterministic, tiny message space). Use randomized padding and encrypt longer blocks instead.");return 0;}
