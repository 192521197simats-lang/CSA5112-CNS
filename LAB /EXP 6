
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char cipher[1000];
    int a = 3, b = 15;
    int a_inv = 9;
    int i, y, x;

    printf("Enter the ciphertext: ");
    fgets(cipher, sizeof(cipher), stdin);

    printf("Decrypted plaintext: ");

    for (i = 0; cipher[i] != '\0'; i++) {
        if (isupper((unsigned char)cipher[i])) {
            y = cipher[i] - 'A';
            x = (a_inv * (y - b + 26)) % 26;
            printf("%c", x + 'A');
        } else if (islower((unsigned char)cipher[i])) {
            y = toupper((unsigned char)cipher[i]) - 'A';
            x = (a_inv * (y - b + 26)) % 26;
            printf("%c", x + 'a');
        } else {
            printf("%c", cipher[i]);
        }
    }

    printf("\n");
    return 0;
}
