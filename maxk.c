#include <stdio.h>
#include <stdlib.h>
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))

void scanArray(long set[], long size) //считывает эл-ты массива
{
    for (long i = 0; i <= size - 1; i++)
    {
        scanf("%li", &set[i]);
    }
}

long long maxSum(long arr[], long k, long size)
{
    long long result = 0;
    for (long i = 0; i < k; i++ )//сумма от начала до k
    {
        result += arr[i];
    }
    long long currentSum = result;
    for (long i = k; i < size; i++)
    {
        currentSum += arr[i] - arr[i - k];
        result = MAX(result, currentSum);
    }
    return result;

}


int main(int argc, char **argv)
{
    long n, k;
    scanf("%li", &n);
    long a[n];
    scanArray(a, n);
    scanf("%li", &k);
    long long result = maxSum(a, k, n);
    printf("%lli", result);
    
    return 0;
}