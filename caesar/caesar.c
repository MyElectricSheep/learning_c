#include <cs50.h>
// https://cs50.readthedocs.io/libraries/cs50/c/
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

bool only_digits(string s);
void print_usage(void);
char rotate(char c, int key);
void print_cipher(string s, int key);

bool only_digits(string s)
{
    int string_length = strlen(s);

    int result = 1; // all chars are digits

    for (int i = 0; i < string_length; i++)
    {
        if (!isdigit(s[i]))
        {
            result = 0; // at least one char is not a digit
        }
    }

    return result;
}

void print_usage(void)
{
    printf("Usage: ./caesar key\n");
}

// Then, implement a function called, e.g., rotate, that takes a char as input and also an int,
// and rotates that char by that many positions if it’s a letter (i.e., alphabetical),
// wrapping around from Z to A (and from z to a) as needed.
// If the char is not a letter, the function should instead return the same char unchanged.

char rotate(char c, int key)
{
    if (!isalpha(c))
    {
        return c;
    }

    int ascii_code = (int)c;

    // ASCII Table for alphabetical characters:
    // https://upload.wikimedia.org/wikipedia/commons/d/dd/ASCII-Table.svg
    // A = 65 ~ Z = 90
    // a = 97 ~ z = 122
    // Formula: Ci = (Pi + k) % 26

    if (isupper(c))
    {
        ascii_code -= 65;
    }
    else
    {
        ascii_code -= 97;
    }

    // printf("\nthe indexed ascii_code of %c is %d\n", c, ascii_code);

    int encoded_letter = (ascii_code + key) % 26;

    if (isupper(c))
    {
        encoded_letter += 65;
    }
    else
    {
        encoded_letter += 97;
    }

    // printf("\nthe encoded equivalent of %c is %c\n", c, (char)encoded_letter);

    return (char)encoded_letter;
}

void print_cipher(string s, int key)
{
    printf("ciphertext: ");
    // char test = rotate(plaintext[0], key);
    int string_length = strlen(s);

    for (int i = 0; i < string_length; i++)
    {
        char next_char = rotate(s[i], key);
        printf("%c", next_char);
    }
    printf("\n");
}

int main(int argc, string argv[])
{

    // Check the correct numbers of arguments provided (max 1)
    if (argc != 2)
    {
        print_usage();
        return 1;
    }

    // Check if every char in the provided arg string is a digit
    string key_string = argv[1];
    int is_digit = only_digits(key_string);

    // printf("the provided argument is_digit result is %d\n", is_digit);

    if (!is_digit)
    {
        print_usage();
        return 1;
    }

    // Convert the key (still a string) to an int
    int key = atoi(key_string);
    // printf("The argument supplied is %d\n", key);

    string plaintext = get_string("plaintext:  ");

    print_cipher(plaintext, key);

    return 0;
}