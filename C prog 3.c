#include <stdio.h>
#include <stdlib.h>

void combined(int *first, int *first_length, int *second, int *second_length, int *return_array, int *result_length);

int main() {
    int first_length = random() % 11 + 10;
    int second_length = random() % 11 + 10;

    int first[first_length];
    int second[second_length];

    for (int i = 0; i < first_length; i++)
        first[i] = random() % 100;

    for (int i = 0; i < second_length; i++)
        second[i] = random() % 100;

    printf("array 1:\n");
    for (int i = 0; i < first_length; i++)
        printf("%d ", first[i]);
    printf("\n");

    printf("array 2:\n");
    for (int i = 0; i < second_length; i++)
        printf("%d ", second[i]);
    printf("\n");

    int joint[first_length + second_length];
    int result_length;

    combined(first, &first_length, second, &second_length, joint, &result_length);

    printf("combined array:\n");
    for (int i = 0; i < result_length; i++)
        printf("%d ", joint[i]);
    printf("\n");

    return 0;
}

void combined(int *first, int *first_length, int *second, int *second_length, int *return_array, int *result_length) {
    int i = 0,
        j = 0,
        k = 0;

    while (i < *first_length && j < *second_length) {
        return_array[k++] = first[i++];
        return_array[k++] = second[j++];
    }

    while (i < *first_length)
        return_array[k++] = first[i++];

    while (j < *second_length)
        return_array[k++] = second[j++];

    *result_length = k;
}
