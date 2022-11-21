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
    for(int i = 1; i <= length; i++)
    {
        if(((s[i-1] == ' ') || i == 1 ) && ((s[i] != ' ') &&(s[i] != '\n')))
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