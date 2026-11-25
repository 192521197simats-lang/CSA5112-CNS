/* EXP 36: Affine Cipher (Repeat)
 * CNS lab solution. Readable, line-by-line C source.
 */
#include <stdio.h>
#include <ctype.h>

int gcd(int a, int b)
{
    while (b) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}
int main(void)
{
    char text[500];
    int a, b;
    printf("Plaintext: ");
    fgets(text, sizeof(text), stdin);
    printf("Enter a and b (a must be coprime with 26): ");
    scanf("%d%d", &a, &b);
    if (gcd(a, 26) != 1) {
        printf("Invalid a: gcd(a,26) must be 1.\n");
        return 1;
    }
    for (int i = 0; text[i]; i++) {
        if (isupper((unsigned char)text[i]))
            text[i] = (char)('A' + (a * (text[i] - 'A') + b) % 26);
        else if (islower((unsigned char)text[i]))
            text[i] = (char)('a' + (a * (text[i] - 'a') + b) % 26);
    }
    printf("Ciphertext: %s", text);
    return 0;
}
