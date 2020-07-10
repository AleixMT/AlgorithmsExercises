//
// Created by axl on 10/7/20.
//

#include "isPrime.h"

bool isPrime(long long unsigned int number)
{
    for (long long unsigned int i = number - 1; i > 1; i--)
    {
        if (number % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main ()
{
    long long unsigned int number;
    printf("\nIntroduce natural number: ");
    if (scanf("%u", &number) == 1)
    {
        printf("\n");
        if (isPrime(number))
        {
            printf("\nThe number is prime");
        }
        else
        {
            printf("\nThe number is not prime");
        }
    }
    printf("\n");
}