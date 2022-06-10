#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
} candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Print the status of all candidates so far
    // printf("#########################\n");
    // for (int x = 0; x < voter_count; x++) {
    //      printf("Voter %i's ranking choices are: ", x + 1);
    //     for (int y = 0; y < candidate_count; y++) {
    //         printf("%i.", preferences[x][y]);
    //     }
    //     printf("\n");
    // }
    // printf("#########################\n");

    // Keep holding runoffs until winner exists
    while (true)
    {

        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // printf("After print_winner()\n");

        // Eliminate last-place candidates
        int min = find_min();
        // printf("Min is %i\n", min);

        bool tie = is_tie(min);

        // printf("tie is %s\n", tie ? "true" : "false");

        // break;

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    for (int i = 0; i < candidate_count; i++)
    {
        int nameMatch = strcmp(candidates[i].name, name);
        if (nameMatch == 0)
        {
            // printf("Candidate %i is %s\n", i, candidates[i].name);

            // Assuming the following candidates: Ben: 0 / Alice: 1 / Bob: 2
            // preferences[MAX_VOTERS][MAX_CANDIDATES] = [[1, 0, 2], [0, 1, 2], [0, 2, 1]]
            // corresponds to: Alice/Ben/Bob + Ben/Alice/Bob + Ben/Bob/Alice
            preferences[voter][rank] = i;
            return true;
        }
    }
    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    // printf("=== tabulating ===\n");
    for (int i = 0; i < voter_count; i++)
    {

        for (int j = 0; j < candidate_count; j++)
        {

            int targetCandidateIndex = preferences[i][j];
            candidate *topChoiceCandidate = &candidates[targetCandidateIndex];
            // printf("%s\n", topChoiceCandidate->name);
            if (!topChoiceCandidate->eliminated)
            {
                topChoiceCandidate->votes++;
                break;
            }
            //  printf("votes %i\n", topChoiceCandidate->votes);
        }
    }

    // for (int c = 0; c < candidate_count; c++) {
    //      printf("Candidate %s has %d votes\n", candidates[c].name, candidates[c].votes);
    //  }
    //  printf("=== end tabulating ===\n");
    return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    int majority = floor(voter_count / 2);
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > majority)
        {
            printf("%s\n", candidates[i].name);
            return true;
        }
    }
    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            if (candidates[i].votes > candidates[j].votes && !candidates[i].eliminated && !candidates[j].eliminated)
            {
                candidate temp = candidates[i];
                candidates[i] = candidates[j];
                candidates[j] = temp;
            }
        }
    }
    // printf("Candidate with the lowest amount of votes: %s\n", candidates[0].name);

    return candidates[0].votes;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    int notEliminated = 0;
    int tieCount = 0;

    for (int i = 0; i < candidate_count; i++)
    {
        if (!candidates[i].eliminated)
        {
            notEliminated++;
            if (candidates[i].votes == min)
            {
                tieCount++;
            }
        }
    }

    if (tieCount == notEliminated)
    {
        return true;
    }

    return false;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == min)
        {
            candidates[i].eliminated = true;
        }
    }
    return;
}