#include <stdio.h>

void meow(int n);

int main(void)
{
    meow(3);
}

void meow(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("meow\n");
    }
}

// If you want a program that prints meow 3x
//int main(void)
//{
//    printf("meow\n");
//    printf("meow\n");
//    printf("meow\n");
//}

// While loop example
// {
//     int i = 0;
//     while (i < 3)
//     {
//         printf("meow\n");
//         i++;
//     }
//}


// For loop example
//{
//    for (int i = 0; i < 3; i++)
//    {
//        printf("meow\n");
//    }
//}