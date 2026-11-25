/* EXP 8: Keyword Monoalphabetic Cipher
 * CNS lab solution. Readable, line-by-line C source.
 */
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    char keyword[100], alphabet[27], cipher[500];
    int used[26] = {0}, k = 0;
    printf("Keyword: ");
    scanf("%99s", keyword);
    for (int i = 0; keyword[i]; i++) {
        char c = toupper((unsigned char)keyword[i]);
        if (isalpha((unsigned char)c) && !used[c - 'A']) {
            alphabet[k++] = c;
            used[c - 'A'] = 1;
        }
    }
    for (int i = 0; i < 26; i++)
        if (!used[i]) alphabet[k++] = 'A' + i;
    alphabet[26] = '\0';
    printf("Plaintext: ");
    scanf(" %499[^\n]", cipher);
    for (int i = 0; cipher[i]; i++) {
        if (isalpha((unsigned char)cipher[i])) {
            int p = toupper((unsigned char)cipher[i]) - 'A';
            cipher[i] = isupper((unsigned char)cipher[i]) ? alphabet[p] : tolower(alphabet[p]);
        }
    }
    printf("Cipher alphabet: %s\nCiphertext: %s\n", alphabet, cipher);
    return 0;
}
