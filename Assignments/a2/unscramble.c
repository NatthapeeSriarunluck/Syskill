#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int compareChars(const void *a, const void *b)
{
    const char *char1 = (const char *)a;
    const char *char2 = (const char *)b;
    return (tolower(*char1) - tolower(*char2));
}

int main(int argc, char *argv[])
{
    printf("working");
    (void)argc;
    FILE *jumble;
    FILE *dictionary;

    char jumbledWord[50];
    char dictionaryWord[50];
    char tempDictionaryWord[50];
    int count = 0;

    jumble = fopen(argv[2], "r");
    while (fscanf(jumble, "%s\n", jumbledWord) != EOF)
    {
        printf("%s: ", jumbledWord);
        qsort(jumbledWord, strlen(jumbledWord), sizeof(char), compareChars);

        dictionary = fopen(argv[1], "r");
        while (fscanf(dictionary, "%s\n", dictionaryWord) != EOF)
        {
            strcpy(tempDictionaryWord, dictionaryWord);
            qsort(tempDictionaryWord, strlen(tempDictionaryWord), sizeof(char), compareChars);
            if (strcmp(jumbledWord, tempDictionaryWord) == 0)
            {
                printf("%s ", dictionaryWord);
                count++;
            }
        }
        if (count == 0)
        {
            printf("NO MATCHES");
        }
        count = 0;
        printf("\n");
        fclose(dictionary);
    }
    fclose(jumble);
    return 0;
}