#include <stdio.h>
#include <math.h>

void scanArray(long array[], int size) //считывает эл-ты массива
{
    for (int i = 0; i <= size - 1; i++)
    {
        scanf("%li", &array[i]);
    }
}

int power2(long number)
{
    while(number > 1)
    {
        if((number % 2)== 1)
        {
            return 0;
        }
        number = (number+2-1)/ 2;
    }
    return 1;
}

void allSums(long array[], int n, int size, long sum)
{
    if (n > size)
    {
        printf("%li ", sum);
        return;
    }
    allSums(array, n+1, size, sum + array[n]); //включает в себя n-ый элемент

    allSums(array, n+1, size, sum); //не включает n-ый элемент
}

int main(int argc, char **argv)
{
    // int n = 0;// кол-во элементов
    // scanf("%i", &n);
    // long numbers[n];
    // scanArray(numbers, n);

    long array[3] = {-1, 3, 7};
    long sum = 0;
    allSums(array, 0, 2, 0);

    //printf("%i \n", power2(33554431));
    
    return 0;
}