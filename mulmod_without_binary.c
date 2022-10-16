#include <stdio.h>

int main(int argc, char **argv)
{
    unsigned long long a, b, m, b2, result;
    unsigned long long i = 0; // i-номер двоичного разряда;
    unsigned long long arr[64];
    printf("input\n");
    scanf("%llu %llu %llu", &a, &b, &m);
    b2 = b;
    while (b2 > 0) // перевод b в двоичное представление (в обратном порядке)
    {
        arr[i] = b2 % 2;
        b2 /= 2;
        ++i;
    }
    result = a * arr[i - 1];
    i--;

    for (; i >= 1; --i)
    {
        result = result * 2;
        result = result + (a * arr[i-1]);
    }
    result = result % m;
    printf("%llu\n", result);
    return 0;
}
// a 9223372036854775807
// b 6515456464654754744
// c 5656555565565656
// 171341810753064
