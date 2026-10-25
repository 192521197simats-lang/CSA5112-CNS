#include <stdio.h>
#include <string.h>
#include <ctype.h>

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    char text[100];
    int a, b, i, inv = -1;

    printf("Enter a message: ");
    fgets(text, sizeof(text), stdin);

    printf("Enter keys a and b: ");
    scanf("%d %d", &a, &b);

    a = (a % 26 + 26) % 26;
    b = (b % 26 + 26) % 26;

    if (gcd(a, 26) != 1) {
        printf("Invalid key! 'a' must be coprime with 26.\n");
        return 0;
    }

    // Find modular inverse of a
    for (i = 1; i < 26; i++) {
        if ((a * i) % 26 == 1) {
            inv = i;
            break;
        }
    }

    // Encryption
    for (i = 0; text[i] != '\0'; i++) {
        if (isupper((unsigned char)text[i]))
            text[i] = ((a * (text[i] - 'A') + b) % 26) + 'A';
        else if (islower((unsigned char)text[i]))
            text[i] = ((a * (text[i] - 'a') + b) % 26) + 'a';
    }

    printf("Encrypted message: %s", text);

    // Decryption
    for (i = 0; text[i] != '\0'; i++) {
        if (isupper((unsigned char)text[i]))
            text[i] = ((inv * ((text[i] - 'A' - b + 26) % 26)) % 26) + 'A';
        else if (islower((unsigned char)text[i]))
            text[i] = ((inv * ((text[i] - 'a' - b + 26) % 26)) % 26) + 'a';
    }

    printf("Decrypted message: %s", text);

    return 0;
}
