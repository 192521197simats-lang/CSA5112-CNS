#include <stdio.h>
int main(){long double keys=1;for(int i=1;i<=25;i++)keys*=i;printf("Playfair key permutations: 25! = approximately %.0Lf\n",keys);printf("log2(25!) is approximately 83.68 bits\n");puts("Effective key count is reduced because different keyword forms can produce the same 5x5 square; removing duplicates depends on how keys are represented.");return 0;}
