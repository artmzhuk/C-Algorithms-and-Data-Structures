#include <stdio.h>

int main()
{
    int rows = 0;
    int columns = 0;
    scanf("%i", &rows);
    scanf("%i", &columns);
    long matrix[rows][columns];
    for (int i = 0; i <= rows - 1; i++)
    {
        for (int j = 0; j <= columns - 1; j++)
        {
            scanf("%li", &matrix[i][j]);
        }
    }


    for (int i = 0; i <= rows - 1; i++) //проход сверху вниз
    {
        long maxInRow = matrix[i][0]; // наибольший эл-т в данной строке
        int maxColumnIndex = 0;
        for (int j = 0; j <= columns - 1; j++) //проход слева направо
        {
            if (matrix[i][j] > maxInRow)
            {
                maxInRow = matrix[i][j];
                maxColumnIndex = j;
            }
            // printf("%li ", matrix[i][j]);
        }
        for (int j = 0; j <= rows - 1; j++) //проверка на минимум в столбце
        {
            if (matrix[j][maxColumnIndex] < maxInRow)
            {
                break;
            }
            if (j == rows - 1)
            {
                printf("%i %i", i, maxColumnIndex);
                return 0;
            }
        }
        // printf("%li ", maxColumnIndex);
    }
    printf("none");
    return 0;
}