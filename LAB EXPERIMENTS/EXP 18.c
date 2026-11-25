#include <stdio.h>
int main(){puts("DES PC-2 selects 24 bits from the left 28-bit half and 24 from the right 28-bit half.");puts("The halves are disjoint, so each subkey has 24 bits from C and 24 bits from D.");puts("This demo shows the structure, not the full DES tables.");for(int r=1;r<=16;r++)printf("K%d = PC2(Cr || Dr): 24 bits from C, 24 bits from D\n",r);return 0;}
