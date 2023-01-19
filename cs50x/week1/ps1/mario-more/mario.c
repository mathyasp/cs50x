#include <cs50.h>
#include <stdio.h>

int main(void)
{
// Create variable that asks user for height
    int n;
    do
    {
        n = get_int("How many rows? ");
    }
    while (n < 1 || n > 8);

// Build the width in spaces
    for (int i = 0; i < n; i++)
    {
        int j = n - i - 1;
        while (j > 0)
        {
            printf(" ");
            j--;
        }

// Left half of pyramid # marks
        int k = 0;
        while (k <= i)
        {
            printf("#");
            k++;
        }

// Add the center column
        printf("  ");

// Right half of pyramid # marks
        int l = 0;
        while (l <= i)
        {
            printf("#");
            l++;
        }
        printf("\n");
    }
}