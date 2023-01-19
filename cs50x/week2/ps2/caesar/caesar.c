#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

char rotate(char c, int k);

// Check length of command-line argument
int main(int argc, string argv[])
{
    int k = 0;
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Check that key is a digit
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    // Turn argv[1] into an int
    k = atoi(argv[1]);

    // Ask for text input print the start of ciphertext response
    string plaintext = get_string("plaintext: ");
    printf("Ciphertext: ");

    // Link to rotate function
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        rotate(plaintext[i], k);
    }
    printf("\n");
}

// Rotate function to print ciphertext
char rotate(char c, int n)
{
    if (isupper(c))
    {
        printf("%c", ((c - 65 + n) % 26 + 65));
    }
    else if (islower(c))
    {
        printf("%c", ((c - 97 + n) % 26 + 97));
    }
    else
    {
        printf("%c", c);
    }
    return 0;
}

