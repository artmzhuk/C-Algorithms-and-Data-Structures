#include <stdio.h>
#include <string.h>

int wcount(char *s)
{
    int counter = 0;
    int length = (int)strlen(s);
    if((length == 0) || (length == 1 && ((s[0] == ' ') || (s[0] == '\n'))))
        return 0;
    if(length == 2 && s[0] != ' ')
        return 1;
    for(int i = 0; i <= length - 1; i++)
    {
        if(s[i] != '\0' && s[i] != '\n' && s[i] != ' ' && ((i != 0 && s[i-1] == ' ') || (i == 0)))
            counter += 1;
    }
    return counter;
}

int main()
{
    char string[1001];
    fgets(string, 1001, stdin);
    printf("%i", wcount(string));
    return 0;
}