/* EXP 4: Polyalphabetic Vigenere Cipher
 * CNS lab solution. Readable, line-by-line C source.
 */
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    char text[500], key[100];
    int j = 0;
    printf("Plaintext: ");
    fgets(text, sizeof(text), stdin);
    printf("Key (letters): ");
    scanf("%99s", key);

    for (int i = 0; text[i]; i++) {
        if (isalpha((unsigned char)text[i])) {
            int shift = toupper((unsigned char)key[j % strlen(key)]) - 'A';
            if (isupper((unsigned char)text[i]))
                text[i] = (char)('A' + (text[i] - 'A' + shift) % 26);
            else
                text[i] = (char)('a' + (text[i] - 'a' + shift) % 26);
            j++;
        }
    }
    printf("Ciphertext: %s", text);
    return 0;
}
