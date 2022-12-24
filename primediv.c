#include <stdio.h>
#include <stdlib.h>

long maxPrime(long xIn){
    long max;
    long x = labs(xIn);
    max = 1;

    while(x % 2 == 0){
        max = 2;
        x /= 2;
    }
    while(x % 3 == 0){
        max = 3;
        x /= 3;
    }

    for(long i = 5; i * i <= x; i += 6){
        /*we need to check only i and i + 2
         because i + 1, i + 3, i + 5 are even
         i + 4 is always divisible by 3 */
        while(x % i == 0){
            max = i;
            x /= i;
        }
        while(x % (i + 2) == 0){
            max = i + 2;
            x /= (i + 2);
        }
    }

    if(x > 4) // case when x itself is a prime number
        max = x;

    return max;
}

int main()
{
    long x;
    scanf("%li", &x);
    long max = maxPrime(x);
    printf("%li", max);

    return 0;
}