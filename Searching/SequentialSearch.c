#include "stdio.h"

int sequentialSearch(int array[], int size, int key) {
    int index = 0;
    int endIndex = size - 1;

    while (index <= endIndex) {
        if (array[index] == key) {
            return index;
        } else {
            index += 1;
        }
    }

    return -1;
}

int main () {

    int size = 10;
    int array[size];
    int key;

    /*====================== Input ======================*/
    printf("Enter the key to search: ");
    scanf("%d", &key);

    printf("Enter %d numbers:\n", size);
    for (int i = 0; i < size; ++i) {
        printf("Data %d: ", i + 1);
        scanf("%d", &array[i]);
    }
    /*====================== Input ======================*/

    /*====================== Output ======================*/
    printf("\nEntered data: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }

    int index = sequentialSearch(array, size, key);
    if (index != -1) {
        printf("\nKey %d was found at index %d", key, index);
    } else {
        printf("\nKey %d was not found", key);
    }
    /*====================== Output ======================*/

    return 0;
}
