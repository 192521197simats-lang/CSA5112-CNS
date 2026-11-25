/* EXP 3: Playfair Cipher
 * CNS lab solution. Readable, line-by-line C source.
 */
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void build_matrix(const char *key, char m[5][5])
{
    int used[26] = {0}, k = 0;
    used['J' - 'A'] = 1;
    for (int pass = 0; pass < 2; pass++) {
        const char *s = pass ? "ABCDEFGHIJKLMNOPQRSTUVWXYZ" : key;
        for (int i = 0; s[i]; i++) {
            char c = toupper((unsigned char)s[i]);
            if (!isalpha((unsigned char)c)) continue;
            if (c == 'J') c = 'I';
            if (!used[c - 'A']) {
                used[c - 'A'] = 1;
                m[k / 5][k % 5] = c;
                k++;
            }
        }
    }
}
void locate(char m[5][5], char c, int *r, int *col)
{
    if (c == 'J') c = 'I';
    for (*r = 0; *r < 5; (*r)++)
        for (*col = 0; *col < 5; (*col)++)
            if (m[*r][*col] == c) return;
}
int main(void)
{
    char key[100], input[500], clean[500], pairs[600], m[5][5];
    int n = 0, p = 0;
    printf("Keyword: ");
    scanf("%99s", key);
    build_matrix(key, m);
    printf("Plaintext: ");
    scanf(" %499[^\n]", input);
    for (int i = 0; input[i]; i++)
        if (isalpha((unsigned char)input[i])) {
            char c = toupper((unsigned char)input[i]);
            clean[n++] = (c == 'J') ? 'I' : c;
        }
    clean[n] = '\0';

    for (int i = 0; i < n; ) {
        char a = clean[i++], b = (i < n) ? clean[i++] : 'X';
        if (a == b) { b = 'X'; i--; }
        pairs[p++] = a; pairs[p++] = b;
    }
    if (p % 2) pairs[p++] = 'X';
    pairs[p] = '\0';

    for (int i = 0; i < p; i += 2) {
        int r1, c1, r2, c2;
        locate(m, pairs[i], &r1, &c1);
        locate(m, pairs[i + 1], &r2, &c2);
        if (r1 == r2) {
            pairs[i] = m[r1][(c1 + 1) % 5];
            pairs[i + 1] = m[r2][(c2 + 1) % 5];
        } else if (c1 == c2) {
            pairs[i] = m[(r1 + 1) % 5][c1];
            pairs[i + 1] = m[(r2 + 1) % 5][c2];
        } else {
            pairs[i] = m[r1][c2];
            pairs[i + 1] = m[r2][c1];
        }
    }
    printf("Ciphertext: %s\n", pairs);
    return 0;
}
