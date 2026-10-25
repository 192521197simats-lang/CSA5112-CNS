#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char text[100], key[100];
    int i, j = 0, shift;

    printf("Enter a message: ");
    fgets(text, sizeof(text), stdin);

    printf("Enter the key: ");
    scanf("%99s", key);

    int len = strlen(text);
    int keylen = strlen(key);

    // Encryption
    for (i = 0; i < len; i++) {
        if (isalpha((unsigned char)text[i])) {
            shift = toupper((unsigned char)key[j % keylen]) - 'A';

            if (isupper((unsigned char)text[i]))
                text[i] = (text[i] - 'A' + shift) % 26 + 'A';
            else
                text[i] = (text[i] - 'a' + shift) % 26 + 'a';

            j++;
        }
    }

    printf("Encrypted message: %s", text);

    // Decryption
    j = 0;

    for (i = 0; i < len; i++) {
        if (isalpha((unsigned char)text[i])) {
            shift = toupper((unsigned char)key[j % keylen]) - 'A';

            if (isupper((unsigned char)text[i]))
                text[i] = (text[i] - 'A' - shift + 26) % 26 + 'A';
            else
                text[i] = (text[i] - 'a' - shift + 26) % 26 + 'a';

            j++;
        }
    }

    printf("Decrypted message: %s", text);

    return 0;
}
