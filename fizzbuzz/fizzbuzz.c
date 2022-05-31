#include <stdio.h>

// Write a fizzbuzz.c program that outputs numbers from 1 to 100.

// But for multiples of 3, print Fizz instead of the number and for the multiples of 5, print Buzz.
// For numbers which are multiples of both 3 and 5, print FizzBuzz.

// 1
// 2
// Fizz
// 4
// Buzz
// Fizz
// 7
// 8
// Fizz
// Buzz
// 11
// Fizz
// 13
// 14
// FizzBuzz

int main(void)
{
    int i = 1;

    while (i <= 100)
    {

        if (i % 3 == 0 && i % 5 == 0)
        {
            printf("FizzBuzz\n");
        }
        else if (i % 3 == 0)
        {
            printf("Fizz\n");
        }
        else if (i % 5 == 0)
        {
            printf("Buzz\n");
        }
        else
        {
            printf("%d\n", i);
        }
        i++;
    }
}