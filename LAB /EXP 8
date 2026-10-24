
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char plain[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char cipher[] = "CIPHERABDGJKLMNOQSTUVWXYZ";
    char text[500];
    int i, j, choice;

    printf("Monoalphabetic Cipher using Keyword CIPHER\n");
    printf("1. Encryption\n");
    printf("2. Decryption\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    getchar();

    printf("Enter the message: ");
    fgets(text, sizeof(text), stdin);

    for (i = 0; text[i] != '\0'; i++) {
        char ch = text[i];
        int upper = isupper((unsigned char)ch);
        char letter = toupper((unsigned char)ch);

        if (letter >= 'A' && letter <= 'Z') {
            if (choice == 1) {
                for (j = 0; j < 26; j++) {
                    if (plain[j] == letter) {
                        text[i] = upper ? cipher[j]
                                        : tolower(cipher[j]);
                        break;
                    }
                }
            } else if (choice == 2) {
                for (j = 0; j < 26; j++) {
                    if (cipher[j] == letter) {
                        text[i] = upper ? plain[j]
                                        : tolower(plain[j]);
                        break;
                    }
                }
            }
        }
    }

    if (choice == 1)
        printf("Encrypted message: %s", text);
    else if (choice == 2)
        printf("Decrypted message: %s", text);
    else
        printf("Invalid choice.\n");

    return 0;
}
