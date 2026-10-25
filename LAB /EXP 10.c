
#include <stdio.h>
#include <ctype.h>
#include <string.h>

char matrix[5][5] = {
    {'M', 'F', 'H', 'I', 'K'},
    {'U', 'N', 'O', 'P', 'Q'},
    {'Z', 'V', 'W', 'X', 'Y'},
    {'E', 'L', 'A', 'R', 'G'},
    {'D', 'S', 'T', 'B', 'C'}
};

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

int main(void) {
    char message[] =
        "Must see you over Cadogan West. Coming at once.";
    char text[200], a, b;
    int i, n = 0, r1, c1, r2, c2;

    /* Remove spaces and punctuation */
    for (i = 0; message[i] != '\0'; i++) {
        if (isalpha((unsigned char)message[i])) {
            a = toupper((unsigned char)message[i]);

            if (a == 'J')
                a = 'I';

            text[n++] = a;
        }
    }

    text[n] = '\0';

    /* Form pairs, inserting X for repeated letters */
    char pairs[300];
    int p = 0;

    for (i = 0; i < n; ) {
        a = text[i++];
        b = (i < n) ? text[i] : 'X';

        if (a == b) {
            b = 'X';
        } else {
            i++;
        }

        pairs[p++] = a;
        pairs[p++] = b;
    }

    pairs[p] = '\0';

    printf("Encrypted message: ");

    for (i = 0; i < p; i += 2) {
        findPosition(pairs[i], &r1, &c1);
        findPosition(pairs[i + 1], &r2, &c2);

        if (r1 == r2) {
            /* Same row: shift right */
            c1 = (c1 + 1) % 5;
            c2 = (c2 + 1) % 5;
        } else if (c1 == c2) {
            /* Same column: shift down */
            r1 = (r1 + 1) % 5;
            r2 = (r2 + 1) % 5;
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
