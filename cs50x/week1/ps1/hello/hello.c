// Load libraries
#include <stdio.h>
#include <cs50.h>

// create function, void for no input
int main(void)
{
    // Ask user their name
    string name = get_string("What is your name? ");
    // Respond to user with, hello, their name
    printf("hello, %s\n", name);
}