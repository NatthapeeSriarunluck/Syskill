#include <stdio.h>
#include <ctype.h>

int main()
{
    int freqArr[26] = {0};
    int character;
    while ((character = getchar()) != EOF)
    {
        // creates an array that stores the frequencies of each alphabet.
        if (isalpha(character))
        {
            int i = 0;

            freqArr[tolower(character) - 'a']++;
            i++;
        }
    }

    // finds the character with the greatest frequency.
    int greatestFreq = 0;
    for (int i = 0; i < 26; i++)
    {
        if (freqArr[i] > greatestFreq)
        {
            greatestFreq = freqArr[i];
        }
    }
    for (int row = greatestFreq; row > 0; row--)
    {
        for (int letter = 0; letter < 26; letter++)
        {
            if (freqArr[letter] >= row)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    printf("abcdefghijklmnopqrstuvwxyz\n");
    return 0;
}
