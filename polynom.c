#include <stdio.h>

int main(int argc, char **argv)
{
    
    long long n;
    long long x0;
    long long pol;
    long long dpol;
    //printf("Enter n:\n");
    scanf("%lld", &n);
    //printf("Enter x0:\n");
    scanf("%lld", &x0);
    long long arr[n];
    for (long long i = n; i >= 0; i--)
    {
        //printf("Enter a%i:\n", i);
        scanf("%lld", &arr[i]);
    }
    pol = arr[n] * x0 + arr[n - 1];
    for (long long j = 2; j <= n; j++)
    {
        pol = pol * x0 + arr[n - j];
    }
    printf("%lld\n", pol);
    dpol = n * arr[n] * x0 + arr[n - 1] * (n - 1);
    for (long long j = n - 2; j >= 1; j--)
    {
        dpol = dpol * x0 + arr[j] * j;
    }
    printf("%lld", dpol);
    return 0;}