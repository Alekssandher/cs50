#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

string replace_letters(char arg[26], string text)
{
    int n = strlen(text);
    static char result[150];

    for (int i = 0; i < n; i++)
    {
        char character = text[i];
        if (isalpha(character))
        {
            int index = tolower(character) - 'a';
            char substitute = arg[index];

            if (isupper(character))
            {
                result[i] = toupper(substitute);
            }
            else
            {
                result[i] = tolower(substitute);
            }
        }
        else
        {
            result[i] = character;
        }
    }

    result[n] = '\0';

    return result;
}

bool has_duplicates(string key)
{
    for (int i = 0; i < 26; i++)
    {
        for (int j = i + 1; j < 26; j++)
        {
            if (tolower(key[i]) == tolower(key[j]))
            {
                return true;
            }
        }
    }
    return false;
}

bool is_valid_key(string key)
{
    if (strlen(key) != 26)
    {
        printf("The key must have 26 letters.\n");
        return false;
    }

    for (int i = 0; i < 26; i++)
    {
        if (!isalpha(key[i]))
        {
            printf("The key must be a string.\n");
            return false;
        }
    }

    if (has_duplicates(key))
    {
        printf("Key shouldn't have duplicte letters.\n");
        return false;
    }

    return true;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("This program only receives 1 argument as input.\n");
        return 1;
    }

    string key = argv[1];

    if (!is_valid_key(key))
    {
        return 1;
    }

    string plain_text = get_string("plaintext: ");

    string result = replace_letters(key, plain_text);
    printf("ciphertext: %s\n", result);

    return 0;
}
