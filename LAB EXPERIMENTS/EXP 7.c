/* EXP 7: Simple Substitution Decryption
 * CNS lab solution. Readable, line-by-line C source.
 */
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    char cipher[500], key[27], plain[500];
    printf("Ciphertext: ");
    fgets(cipher, sizeof(cipher), stdin);
    printf("Enter the substitution alphabet (cipher A-Z mapping): ");
    scanf("%26s", key);
    for (int i = 0; cipher[i]; i++) {
        char c = cipher[i];
        if (isalpha((unsigned char)c)) {
            int idx = -1;
            for (int j = 0; j < 26; j++)
                if (toupper((unsigned char)key[j]) == toupper((unsigned char)c)) {
                    idx = j; break;
                }
            plain[i] = (idx < 0) ? c : (char)('A' + idx);
        } else plain[i] = c;
    }
    plain[strlen(cipher)] = '\0';
    printf("Possible plaintext: %s\n", plain);
    return 0;
}
