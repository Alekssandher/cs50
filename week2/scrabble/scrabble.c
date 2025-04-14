#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int get_score(string word)
{
    int score = 0;

    for (int i = 0, len = strlen(word); i < len; i++)
    {
        char upper = toupper(word[i]);
        if (upper >= 'A' && upper <= 'Z')
        {
            score += points[upper - 'A'];
        }
    }

    return score;
}

int main()
{

    string p1_input = get_string("Player 1: ");
    string p2_input = get_string("Player 2: ");

    int p1_score = get_score(p1_input);
    int p2_score = get_score(p2_input);

    if (p1_score > p2_score)
    {
        printf("Player 1 wins!\n");
    }
    else if (p2_score > p1_score)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }

    return 0;
}
