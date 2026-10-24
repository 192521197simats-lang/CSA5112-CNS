#include <stdio.h>
#include <string.h>
#include <ctype.h>

int modInverse(int a, int m) {
    a = (a % m + m) % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) return x;
    }
    return -1;
}

int main() {
    char plaintext[] = "meetmeattheusualplaceattenratherthaneightoclock";
    int K[2][2] = {{9, 4}, {5, 7}};

    int len = strlen(plaintext);
    if (len % 2 != 0) {
        plaintext[len] = 'x';
        plaintext[len + 1] = '\0';
        len++;
    }

    // Encryption
    char ciphertext[len + 1];
    ciphertext[len] = '\0';

    for (int i = 0; i < len; i += 2) {
        int p1 = plaintext[i] - 'a';
        int p2 = plaintext[i + 1] - 'a';

        int c1 = (K[0][0] * p1 + K[0][1] * p2) % 26;
        int c2 = (K[1][0] * p1 + K[1][1] * p2) % 26;

        ciphertext[i] = c1 + 'a';
        ciphertext[i + 1] = c2 + 'a';
    }

    // Decryption setup
    int det = (K[0][0] * K[1][1] - K[0][1] * K[1][0]) % 26;
    det = (det + 26) % 26;
    int detInverse = modInverse(det, 26);

    int K_inv[2][2];
    K_inv[0][0] = (K[1][1] * detInverse) % 26;
    K_inv[0][1] = ((-K[0][1] + 26) * detInverse) % 26;
    K_inv[1][0] = ((-K[1][0] + 26) * detInverse) % 26;
    K_inv[1][1] = (K[0][0] * detInverse) % 26;

    char decrypted[len + 1];
    decrypted[len] = '\0';

    for (int i = 0; i < len; i += 2) {
        int c1 = ciphertext[i] - 'a';
        int c2 = ciphertext[i + 1] - 'a';

        int p1 = (K_inv[0][0] * c1 + K_inv[0][1] * c2) % 26;
        int p2 = (K_inv[1][0] * c1 + K_inv[1][1] * c2) % 26;

        decrypted[i] = p1 + 'a';
        decrypted[i + 1] = p2 + 'a';
    }

    printf("Plaintext:  %s\n", plaintext);
    printf("Ciphertext: %s\n", ciphertext);
    printf("Decrypted:  %s\n", decrypted);

    return 0;
}
