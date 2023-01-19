#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

bool has_letters(string text);
bool key_length(string text);
bool unique_char(string text);
string cipher(string key, string words);


int main(int argc, string argv[])
{
    // Refuse any arguments that aren't = 2 aka the first text after the file name
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // Refuse any arguments that don't contain exactly 26 unique letters
    else if ((!key_length(argv[1])) || (!has_letters(argv[1])) || (!unique_char(argv[1])))
    {
        return 1;
    }

    // Turn accepted argument into a string
    string key = argv[1];

    // Ask user for the text they wish to be enciphered
    string plaintext = get_string("plaintext: ");

    // Initiate the response
    printf("ciphertext: ");

    // Use the cipher function to use the key and the plaintext to return the enciphered text
    cipher(key, plaintext);

}

// Check if command line has only 26 characters
bool key_length(string text)
{
    if (strlen(text) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return false;
    }
    return true;
}

// Check if command line has letters only
bool has_letters(string text)
{
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (!isalpha(text[i]))
        {
            printf("Key must contain only letters.\n");
            return false;
        }
    }
    return true;
}

// Check if all characters in command line are unique
bool unique_char(string text)
{
    for (int i = 0, n = strlen(text); i < n - 1; i++)
    {
        for (int j = i + 1, m = strlen(text); j < m; j++)
        {
            if (text[i] == text[j])
            {
                printf("Key must contain only unique characters.\n");
                return false;
            }
        }
    }
    return true;
}

// Detect cipher - index the key with alphabet
string cipher(string key, string words)
{
    for (int i = 0, n = strlen(words); i < n; i++)
    {
        if (isalpha(words[i]))
        {
            if (isupper(words[i]))
            {
                // For uppercase values, print the encrypted word regardless of the key's case
                for (int j = 0, m = strlen(key); j < m; j++)
                {
                    if (words[i] == 'A' + j)
                    {
                        printf("%c", toupper(key[j]));
                    }
                }
            }
            else if (islower(words[i]))
            {
                // For lowercase values, print the encrypted word regardless of the key's case
                for (int j = 0, m = strlen(key); j < m; j++)
                {
                    if (words[i] == 'a' + j)
                    {
                        printf("%c", tolower(key[j]));
                    }
                }
            }
        }
        // For non-alphabetical values, simply print the value (i.e., punctuation)
        else
        {
            printf("%c", words[i]);
        }
    }
    printf("\n");
    return 0;
}
