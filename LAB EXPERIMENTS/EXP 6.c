/* EXP 6: Affine Cipher Frequency Attack
 * CNS lab solution. Readable, line-by-line C source.
 */
#include <stdio.h>
#include <ctype.h>

int gcd(int a, int b) {
    while (b) { int t = b; b = a % b; a = t; }
    return a;
}
int main(void)
{
    char cipher[1000];
    int freq[26] = {0}, total = 0;
    printf("Enter affine ciphertext: ");
    fgets(cipher, sizeof(cipher), stdin);
    for (int i = 0; cipher[i]; i++)
        if (isalpha((unsigned char)cipher[i])) {
            freq[toupper((unsigned char)cipher[i]) - 'A']++;
            total++;
        }
    printf("Cipher letter frequencies:\n");
    for (int i = 0; i < 26; i++)
        printf("%c: %d (%.1f%%)\n", 'A' + i, freq[i],
               total ? 100.0 * freq[i] / total : 0.0);
    printf("\nCandidate decryptions (all valid affine keys):\n");
    for (int a = 1; a < 26; a++) {
        if (gcd(a, 26) != 1) continue;
        for (int b = 0; b < 26; b++) {
            int inv = 1;
            while ((inv * a) % 26 != 1) inv++;
            printf("a=%2d b=%2d: ", a, b);
            for (int i = 0; cipher[i]; i++) {
                char c = cipher[i];
                if (isalpha((unsigned char)c)) {
                    int x = (toupper((unsigned char)c) - 'A' - b + 26) % 26;
                    putchar('A' + (inv * x) % 26);
                } else putchar(c);
            }
            putchar('\n');
        }
    }
    return 0;
}
