
#include <stdio.h>
#include <string.h>

int main(void) {
    char cipher[] =
        "53‡‡†305))6*;4826)4‡.)4‡);806*;48†8¶60))85;;"
        "]8*;:‡*8†83(88)5*†;46(;88*96*?;8)*‡(;485);"
        "5*†2:*‡(;4956*2(5*—4)8¶8*;4069285);)6†8)"
        "4‡‡;1(‡9;48081;8:8‡1;48†85;4)485†528806*81"
        "(‡9;48;(88;4(‡?34;48)4‡;161;:188;‡?";

    int freq[256] = {0};
    int i;

    for (i = 0; cipher[i] != '\0'; i++) {
        unsigned char ch = (unsigned char)cipher[i];
        if (ch < 128)
            freq[ch]++;
    }

    printf("Character frequencies:\n");

    for (i = 0; i < 128; i++) {
        if (freq[i] > 0 && i >= 32)
            printf("%c : %d\n", i, freq[i]);
    }

    return 0;
}
