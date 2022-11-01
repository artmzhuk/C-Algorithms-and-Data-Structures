#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    long long n;
    //printf("input: ");
    scanf("%lld", &n);
    n = llabs(n);
    char *a = malloc(n);

    for (long long i = 0; i <= n; i++)
    {
        a[i] = 1;
    }
    
    //printf ("test1\n");
    for (long long i = 2; i*i <= n; i++)
    {
        if (a[i] == 1)
        {
            for (long long j = i * i; j <= n; j += i )
            {
                a[j] = 0;
            }
        }
    }
    //printf ("test2\n");

    for (long long i = n; i >= 2; i--)
    {
        if (a[i] == 1)
        {
            if (n % i == 0)
            {
                printf ("%lld ", i);
                return 0;
            }
        }
        
    }
    
    
    /*for (long long i = 2; i <= n; i++)
    {
        if (a[i] == 1)
        {
            printf("%lld ", i);
        }
        
    }*/ // рабочий вариант вывода простых чисел
    //printf ("\ntest3\n");
    /*for (long long j = 0; j <= n; j++) // вывод массива для отладки
    {
        printf("%lld ", a[j]);
    }*/

    return 0;
}