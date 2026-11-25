#include <stdio.h>
int main(){puts("CBC-MAC extension attack for one-block X:");puts("Let T=MAC(K,X). For two-block message X || (X XOR T), CBC-MAC can be made equal to T under the basic construction (with no length binding).");puts("This demonstrates why CBC-MAC must be used with fixed-length messages or proper domain/length handling; CMAC fixes this issue.");return 0;}
