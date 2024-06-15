#include <stdio.h>
#include <stdlib.h>

int **create_array(int rows, int cols)
{
    int **array = malloc(rows * sizeof(int *));

    if (array == NULL)
    {
        fprintf(stderr, "Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < rows; i++)
    {
        array[i] = malloc(cols * sizeof(int));

        if (array[i] == NULL)
        {
            fprintf(stderr, "Memory allocation failed");
            exit(EXIT_FAILURE);
        }
    }

    return array;
}

void populate(int **array, int rows, int cols)
{
    int value = 1;

    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            array[r][c] = value;
            ++value;
        }
    }
}

void print(int **array, int rows, int cols)
{
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            printf("row:%d col:%d value:%d address:%p \n", r, c, array[r][c], &array[r][c]);
        }
    }
}

void clean(int **array, int rows, int cols)
{
    for (int r = 0; r < rows; r++)
    {
        free(array[r]);
    }

    free(array);
}

int main()
{
    int rows = 5;
    int cols = 10;

    int **array = create_array(rows, cols);
    populate(array, rows, cols);
    print(array, rows, cols);
    clean(array, rows, cols);

    return EXIT_SUCCESS;
}
