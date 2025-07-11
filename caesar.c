#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cipher_caesar(string plaintext, int key);

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        for (int i = 0, L = strlen(argv[1]); i < L; i++)
        {
            if (isdigit(argv[1][i]) == false)
            {
                printf("Usage: ./caesar ker\n");
                return 1;
            }
        }
        int key = atoi(argv[1]);

        string plaintext = get_string("plaintext: ");
        printf("ciphertext: ");
        cipher_caesar(plaintext, key);
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}

void cipher_caesar(string plaintext, int key)
{
    for (int i = 0, L = strlen(plaintext); i < L; i++)
    {
        if (plaintext[i] >= 'a' && plaintext[i] <= 'z')
        {
            printf("%c", ((((plaintext[i] - 'a') + key) % 26) + 'a'));
        }
        else if (plaintext[i] >= 'A' && plaintext[i] <= 'Z')
        {
            printf("%c", ((((plaintext[i] - 'A') + key) % 26) + 'A'));
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
}
