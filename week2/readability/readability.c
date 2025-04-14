#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_words(string text)
{
    int words_count = 1;

    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (text[i] == ' ')
        {
            words_count++;
        }
    }

    return words_count;
}

int count_letters(string text)
{
    int count = 0;

    for (int i = 0; text[i] != '\0'; i++)
    {
        if (isalpha(text[i]))
        {
            count++;
        }
    }
    return count;
}

int count_sentences(string text)
{
    int sentences = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }

    return sentences;
}

int main()
{
    string text = get_string("Text: ");

    int words_count = count_words(text);

    int letters = count_letters(text);

    int sentences = count_sentences(text);

    double avg_letters = ((double) letters / words_count) * 100.00;
    double avg_sentences = ((double) sentences / words_count) * 100.00;

    int index = round(0.0588 * avg_letters - 0.296 * avg_sentences - 15.8);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", index);
    }

    return 0;
}
