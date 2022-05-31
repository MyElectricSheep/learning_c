#include <stdio.h>
#include <string.h>

// In this project, we will write a program to determine whether two strings are anagrams or not.

// String y is an anagram of string x if y is a rearrangement of string x.
// This implies that y and x have the same letters with the same amount of each letter.
// Example: “code” and “deco” are anagrams!

// The constraints of this project are: Each string will contain only characters
// that are from the first four letters of the English alphabet (‘a’, ‘b’, ‘c’, ‘d’) and spaces.
// All letters are in lowercase.

// We will do this by creating two arrays of length four: one for each string that represents
// the count of each character. These arrays will serve as counters. In each array, the number at position
// zero corresponds to the count of the letter ‘a’, the number at position one will correspond to the count
// of the letter ’b’ and this pattern will continue for the remaining letters.
// We do not count the number of spaces. For example, “a bc d” would be an anagram of “ab cd”.

// We will then loop through both strings and update their respective counters.

// We will then compare the two counters to see if the two strings are anagrams
// and if they are, we will print “Anagram!”. If they are not, we will print “Not Anagram!”

int main(void)
{

    int flag = 0;

    int counter1[] = {0, 0, 0, 0};
    int counter2[] = {0, 0, 0, 0};

    char s1[] = "dbb cccccaacb cdbababdcdcdab dcdad";
    char s2[] = "bbbcc bdddccccad cdbbaaacaccdabdd";

    for (int i = 0; i < strlen(s1); i++)
    {
        switch (s1[i])
        {
        case 'a':
            counter1[0]++;
            break;
        case 'b':
            counter1[1]++;
            break;
        case 'c':
            counter1[2]++;
            break;
        case 'd':
            counter1[3]++;
            break;
        }
    }

    for (int i = 0; i < strlen(s2); i++)
    {
        switch (s2[i])
        {
        case 'a':
            counter2[0]++;
            break;
        case 'b':
            counter2[1]++;
            break;
        case 'c':
            counter2[2]++;
            break;
        case 'd':
            counter2[3]++;
            break;
        }
    }

    for (int i = 0; i < sizeof(counter1) / sizeof(int); i++)
    {
        if (counter1[i] != counter2[i])
        {
            flag = 1;
        }
    }

    if (flag == 0)
    {
        printf("Anagram!");
    }
    else
    {
        printf("Not Anagram!");
    }
}