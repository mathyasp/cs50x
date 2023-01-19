#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
}

// Count total cents
int get_cents(void)
{
    int cents;
    do
    {
        cents = get_int("What is the change owed? ");
    }
    while (cents < 0);
    return cents;
}

// Count # quarters and calc remainder
int calculate_quarters(int cents)
{
    int q = 0;
    while (cents >= 25)
    {
        cents = cents - 25;
        q++;
    }
    return q;
}

// Count # dimes in what's left and calc remainder
int calculate_dimes(int cents)
{
    int d = 0;
    while (cents >= 10)
    {
        cents = cents - 10;
        d++;
    }
    return d;
}

// Count # nickels in what's left and calc remainder
int calculate_nickels(int cents)
{
    int n = 0;
    while (cents >= 5)
    {
        cents = cents - 5;
        n++;
    }
    return n;
}


// Count # pennies in what's left
int calculate_pennies(int cents)
{
    int p = 0;
    while (cents >= 1)
    {
        cents = cents - 1;
        p++;
    }
    return p;
}
