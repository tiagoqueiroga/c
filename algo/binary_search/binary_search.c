#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_SIZE 10

int binary_search(int array[10], int element, int left, int right)
{

    int mid = left + (right - left) / 2;

    if (left > right)
        return -1;

    if (element == array[mid])
        return mid;

    else if (array[mid] > element)
    {
        return binary_search(array, element, left, mid - 1);
    }

    else
    {
        return binary_search(array, element, mid + 1, right);
    }
}

int main(int argc, char **argv)
{

    if (argc < 2)
    {
        fprintf(stderr, "usage: ./binary_search <element>\n");
        exit(EXIT_FAILURE);
    }

    char search_term[10];

    int number = atoi(strcpy(search_term, argv[1]));

    int sorted[ARRAY_SIZE] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    int found_index = 0;

    int left_index = 0;
    int right_index = ARRAY_SIZE - 1;

    found_index = binary_search(sorted, number, left_index, right_index);

    printf("\nfound_index:%d\n", found_index);

    return EXIT_SUCCESS;
}
