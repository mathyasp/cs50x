#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

float letter_count(string texts);
float word_count(string texts);
float sentence_count(string texts);

int main(void)
{
    // Prompt user for text
    string text = get_string("Enter your text: ");

    // Calculate the average letters and sentences in the text
    float avg_letters = letter_count(text) / word_count(text) * 100;
    float avg_sentences = sentence_count(text) / word_count(text) * 100;

    // Calculate the coleman liau vaule and convert to int
    float c_l = (0.0588 * avg_letters) - (0.296 * avg_sentences) - 15.8;
    int coleman_liau = roundf(c_l);

    // Print reading level based on coleman liau value
    if (coleman_liau < 1)
    {
        printf("Before Grade 1\n");
    }

    else if (coleman_liau >= 1 && coleman_liau < 16)
    {
        printf("Grade %i\n", coleman_liau);
    }

    else if (coleman_liau >= 16)
    {
        printf("Grade 16+\n");
    }

}

// Get number of letters
float letter_count(string texts)
{
    int count_letter = 0;

    for (int i = 0, n = strlen(texts); i < n; i++)
    {
        // Count only letters
        if (isalpha(texts[i]))
        {
            count_letter++;
        }
    }
    return count_letter;
}

// Get number of words
float word_count(string texts)
{
    int count_word = 1;

    for (int i = 0, n = strlen(texts); i < n; i++)
    {
        // Count only spaces
        if (isspace(texts[i]))
        {
            count_word++;
        }
    }
    return count_word;
}

// Get number of sentences
float sentence_count(string texts)
{
    int count_sentence = 0;

    // Count "." "?" "!"
    for (int i = 0, n = strlen(texts); i < n; i++)
    {
        if ((texts[i] == '.') || (texts[i] == '?') || (texts[i] == '!'))
        {
            count_sentence++;
        }
    }
    return count_sentence;
}