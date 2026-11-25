/* EXP 1: Caesar Cipher
 * CNS lab solution. Readable, line-by-line C source.
 */
#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char text[500];
    int key;

    printf("Enter plaintext: ");
    fgets(text, sizeof(text), stdin);
    printf("Enter shift key (1-25): ");
    scanf("%d", &key);
    key = ((key % 26) + 26) % 26;

    for (int i = 0; text[i] != '\0'; i++) {
        if (isupper((unsigned char)text[i]))
            text[i] = (char)('A' + (text[i] - 'A' + key) % 26);
        else if (islower((unsigned char)text[i]))
            text[i] = (char)('a' + (text[i] - 'a' + key) % 26);
    }

    printf("Ciphertext: %s", text);
    return 0;
}
