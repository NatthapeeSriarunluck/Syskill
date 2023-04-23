#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    (void)argc;
    int spaceWidth = atoi(argv[2]);
    int character;
    // determine wheter to convert space -> tabs or tabs -> spaces
    if (strcmp(argv[1], "-d") == 0)
    {
        while ((character = getchar()) != EOF)
        {
            if (character == '\t')
            {
                for (int i = 0; i < spaceWidth; i++)
                {
                    putchar(' ');
                }
            }
            else
            {
                putchar(character);
            }
        }
    }
    else if (strcmp(argv[1], "-e") == 0)
    {
        int spaces = 0;
        while ((character = getchar()) != EOF)
        {
            if (character == ' ')
            {
                spaces++;
                if (spaces == spaceWidth)
                {
                    putchar('\t');
                    spaces = 0;
                }
            }
            else
            {
                putchar(character);
                spaces = 0;
            }
        }
    }

    return 0;
}