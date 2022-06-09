#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
} candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    // printf("The name we are looking for is: %s\n", name);
    for (int i = 0; i < MAX; i++)
    {
        if (candidates[i].name)
        {
            // printf("%s\n", candidates[i].name);
            // https://www.programiz.com/c-programming/library-function/string.h/strcmp
            int nameMatch = strcmp(candidates[i].name, name);
            if (nameMatch == 0)
            {
                // printf("it's a match!\n");
                candidates[i].votes++;
                return true;
            }
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{

    // Selection sort algorithm: Best: O(n2), Worst: Ω(n2)
    for (int i = 0; i < MAX; i++)
    {
        for (int j = i + 1; j < MAX; j++)
        {
            if (candidates[i].votes > candidates[j].votes)
            {
                candidate temp = candidates[i];
                candidates[i] = candidates[j];
                candidates[j] = temp;
            }
        }
    }

    // Print the name of the winner by max votes
    printf("%s\n", candidates[MAX - 1].name);

    // If there's a tie, print the name of following candidate(s) afterwards
    for (int i = MAX; i > 0; i--)
    {
        if (candidates[i - 1].votes == candidates[i - 2].votes && candidates[i - 1].votes != 0)
        {
            printf("%s\n", candidates[i - 2].name);
        }
    }

    return;
}