#include <stdio.h>

int main(int argc, char **argv)
{
    
    int n;
    double x0;
    double pol;
    double dpol;
    printf("Enter n:\n");
    scanf("%i", &n);
    printf("Enter x0:\n");
    scanf("%lF", &x0);
    int arr[n];
    for (int i = n; i >= 0; i--)
    {
        printf("Enter a%i:\n", i);
        scanf("%i", &arr[i]);
    }
    pol = arr[n] * x0 + arr[n - 1];
    for (int j = 2; j <= n; j++)
    {
        pol = pol * x0 + arr[n - j];
    }
    printf("%lF\n", pol);
    dpol = n * arr[n] * x0 + arr[n - 1] * (n - 1);
    for (int j = n - 2; j >= 1; j--)
    {
        dpol = dpol * x0 + arr[j] * j;
    }
    printf("%lF", dpol);
    return 0;
}