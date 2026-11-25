/* EXP 2: Monoalphabetic Substitution Cipher
 * CNS lab solution. Readable, line-by-line C source.
 */
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    char text[500], key[27];
    printf("Enter a 26-letter substitution alphabet: ");
    scanf("%26s", key);
    if (strlen(key) != 26) {
        printf("Key must contain 26 letters.\n");
        return 1;
    }

    printf("Enter plaintext (letters only): ");
    scanf(" %499[^\n]", text);

    for (int i = 0; text[i]; i++) {
        if (isalpha((unsigned char)text[i])) {
            int p = toupper((unsigned char)text[i]) - 'A';
            text[i] = (char)(isupper((unsigned char)text[i]) ? toupper(key[p]) : tolower(key[p]));
        }
    }
    printf("Ciphertext: %s\n", text);
    return 0;
}
