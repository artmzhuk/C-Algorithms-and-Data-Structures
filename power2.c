#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void scanArray(long array[], int size) //считывает эл-ты массива
{
    for (int i = 0; i <= size - 1; i++)
    {
        scanf("%li", &array[i]);
    }
}

int power2(long number)
{
    if (number <= 0) //проверка на неположительные числа
    {
        return 0;
    }
    while (number > 1)
    {
        if ((number % 2) == 1)
        {
            return 0;
        }
        number = (number + 2 - 1) / 2;
    }
    return 1;
}

void allSums(long array[], int n, int size, long sum, int *counter)
{
    if (n > size)
    {
        if (power2(sum) == 1)
        {
            *counter = *counter + 1;
        }
        return;
    }
    allSums(array, n + 1, size, sum + array[n], counter); //включает в себя n-ый элемент

    allSums(array, n + 1, size, sum, counter); //не включает n-ый элемент
}

int main(int argc, char **argv)
{
    int size;// кол-во элементов
    scanf("%i", &size);

    long numbers[size];// массив с числами
    scanArray(numbers, size);

    int *counter = malloc(sizeof(int));
    *counter = 0; //счетчик сумм равных степени двойки

    allSums(numbers, 0, size-1, 0, counter);
    printf("%i \n", *counter);


    return 0;
}