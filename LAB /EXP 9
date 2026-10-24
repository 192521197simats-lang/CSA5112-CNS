
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char key[26] = "ROYALNEWZEALANDNAVY";
char matrix[5][5];
int used[26] = {0};

void createMatrix() {
    int i, j, k = 0;
    char alphabet[] = "ABCDEFGHIKLMNOPQRSTUVWXYZ";

    for (i = 0; key[i] != '\0'; i++) {
        char ch = toupper((unsigned char)key[i]);

        if (ch == 'J')
            ch = 'I';

        if (ch >= 'A' && ch <= 'Z' &&
            !used[ch - 'A']) {
            matrix[k / 5][k % 5] = ch;
            used[ch - 'A'] = 1;
            k++;
        }
    }

    for (i = 0; alphabet[i] != '\0'; i++) {
        char ch = alphabet[i];

        if (!used[ch - 'A']) {
            matrix[k / 5][k % 5] = ch;
            used[ch - 'A'] = 1;
            k++;
        }
    }
}

void findPosition(char ch, int *row, int *col) {
    int i, j;

    if (ch == 'J')
        ch = 'I';

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (matrix[i][j] == ch) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

int main() {
    char cipher[] =
        "KXJEYUREBEZWEHEWRYTUHEYFS"
        "KREHEGOYFIWTTTUOLKSYCAJPO"
        "BOTEIZONTXBYBNTGONEYC UZWR"
        "GDSONSXBOUYWRHEBAAHYUSEDQ";

    char text[300];
    int i, n = 0;
    int r1, c1, r2, c2;

    createMatrix();

    printf("Playfair Key Matrix:\n");
    for (i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++)
            printf("%c ", matrix[i][j]);
        printf("\n");
    }

    /* Remove spaces and keep letters only */
    for (i = 0; cipher[i] != '\0'; i++) {
        if (isalpha((unsigned char)cipher[i])) {
            text[n++] = toupper((unsigned char)cipher[i]);
        }
    }
    text[n] = '\0';

    printf("\nDecrypted message:\n");

    for (i = 0; i + 1 < n; i += 2) {
        findPosition(text[i], &r1, &c1);
        findPosition(text[i + 1], &r2, &c2);

        if (r1 == r2) {
            /* Same row: move left */
            c1 = (c1 + 4) % 5;
            c2 = (c2 + 4) % 5;
        } else if (c1 == c2) {
            /* Same column: move up */
            r1 = (r1 + 4) % 5;
            r2 = (r2 + 4) % 5;
        } else {
            /* Rectangle rule */
            int temp = c1;
            c1 = c2;
            c2 = temp;
        }

        printf("%c%c", matrix[r1][c1],
                       matrix[r2][c2]);
    }

    printf("\n");
    return 0;
}
