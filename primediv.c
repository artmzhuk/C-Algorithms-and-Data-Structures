#include <stdio.h>

int main(int argc, char **argv)
{
    long long x;
    long long i = 2;
    long long k = 2;
    long long res;
    printf("input: \n");
    scanf("%lld", &x);
    long long arr[x];
    while (i <= x) // записывает в массив arr числа, индекс совпадает с числом
    {
        arr[i] = i;
        i++;
    }
    while (k <= x) // решето эратосфена
    {
        if (arr[k] != 0)
        {
            for (long long v = 2; k * v <= x; v++)
            {
                arr[k * v] = 1; // заполнение массива 
            }
        }
        k++;
    }

    while (x % arr[k-1] != 0 || arr[k-1] == 1) // поиск наибольшего простого делителя
    {
        k--;
    }
    
    printf("%lld\n", arr[k-1]);

    /*for (int j = 0; j < i; j++) // вывод массива для отладки
    {
        printf("%lld ", arr[j]);
    }*/

    return 0;
}