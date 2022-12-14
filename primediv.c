#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long n, j;
    scanf("%lld", &n);
    n = llabs(n);
    char *sieve = calloc(n + 1, 1);
    long long primes[4800] = {0};
    int index = 0;
    for (long long i = 2; i * i <= n; i++) {
        if (sieve[i] == 0) {
            primes[index] = i;
            index++;
            j = i * i;
            while (j <= n) {
                sieve[j] = 1;
                if (i == 2)
                    j += i;
                else
                    j = j + (2 * i);
            }
        }
    }

    for(int i = index - 1; i >= 0; i--){
        if(n % primes[i] == 0){
            printf("%lld", primes[i]);
            free(sieve);
            return 0;
        }
    }
    printf("%lld", n);
    free(sieve);
    return 0;
}