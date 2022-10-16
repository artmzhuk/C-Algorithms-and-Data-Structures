#include <stdio.h>


int main(int argc, char **argv)
{
    unsigned long long x; 
    unsigned long long fib[95];
    unsigned long long maxF = 2;
    int j = 2;
    int k = 0;
    int fib2[95] = {0};
    scanf("%llu", &x);

    if(x == 1)
    {
        int ans = 1;
        printf("%i", ans);
        
    }

    fib[0]= 1;
    fib[1]= 1;
    while(maxF <= x)
    {
        fib[j] = fib[j-1] + fib[j-2];
        maxF = fib[j];
        j++;
    }

    while(k <= j-2)
    {
        if (x >= fib[j-2-k])
        {
            fib2[j-2-k] = 1;
            x = x - fib[j-2-k];
        }
        k++;
    }
    while(k >= 2)
    {
        printf("%i", fib2[k-1]);
        k--;
    }
}