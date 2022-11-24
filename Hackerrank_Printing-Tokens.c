#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int start;
    int stop;
    int index = 0;

    char *s;
    s = malloc(1024 * sizeof(char));
    scanf("%[^\n]", s);
    s = realloc(s, strlen(s) + 1);
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == ' ')
        {
            s[i] = '\n';
        }
    }
    printf("%s\n", s);
    free(s);
    return 0;
}