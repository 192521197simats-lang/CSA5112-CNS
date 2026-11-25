#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){srand((unsigned)time(NULL));int k1=rand()%1000+1,k2=rand()%1000+1;printf("Illustrative DSA nonce values (not real cryptographic randomness): k1=%d, k2=%d\n",k1,k2);puts("DSA signatures use a per-signature nonce k, so signatures on the same message usually differ. Deterministic RSA signatures (same message and key, same padding scheme) may be repeatable, but secure RSA signatures typically use randomized padding.");puts("Never use rand() for actual cryptographic nonce generation.");return 0;}
