// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <stdio.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1]; // array of chars [45 + 1]
    struct node *next; // pointer to the next node
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 676;

// Hash table
node *table[N];

// Initiate variable
int num_word = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // Hash word to obtain hash number
    int index = hash(word);

    // Create temp node to traverse the list
    node *cursor = table[index];

    // Traverse linked list, looking for the word
    while (cursor != NULL)
    {
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
        else
        {
            cursor = cursor->next;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // If more than 1 character word
    if (word[1] != '\0')
    {
        return ((toupper(word[0]) - 'A') + (toupper(word[1]) - 'A') % 676);
    }
    // If only one character word
    else
    {
        return (toupper(word[0]) - 'A');
    }
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Open the dictionary file to be read
    FILE *dict = fopen(dictionary, "r");

    // Check if NULL
    if (!dict)
    {
        printf("Error opening dictionary\n");
        return false;
    }

    // Create temporary char array to hold each word
    char tmp_word[LENGTH + 1];

    // Read in each word from dictionary, assigning it to tmp_word, one at a time
    while ((fscanf(dict, "%s", tmp_word)) != EOF)
    {
        // Create new node, check if null
        node *new = malloc(sizeof(node));
        if (new == NULL)
        {
            printf("No memory available\n");
            return false;
        }
        // Copy word into new node
        strcpy(new->word, tmp_word);

        // Check if first node of list
        if (table[hash(tmp_word)] == NULL)
        {
            // Next points to NULL
            new->next = NULL;
        }

        // If not first node of list
        else
        {
            // Call to hash funtion and assign value temporarily to next pointer
            new->next = table[hash(tmp_word)];
        }

        // Assign temporary node to the hash table permanently
        table[hash(tmp_word)] = new;

        // Count 1 word
        num_word++;
    }
    // Close the file
    fclose(dict);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return num_word;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];
        while (cursor != NULL)
        {
            node *tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }
    }
    return true;
}
