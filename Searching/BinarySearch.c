#include "stdio.h"

void insertionSort(int array[], int size) {
    for (int i = 1; i < size; i++) {
        int key = array[i];
        int j = i - 1;

        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j--;
        }

        array[j + 1] = key;
    }
}

int binarySearch(int array[], int size, int key) {
    int startIndex = 0;
    int endIndex = size - 1;

    while (startIndex <= endIndex) {
        int middleIndex = (startIndex + endIndex) / 2;

        if (array[middleIndex] == key) {
            return middleIndex;
        } else if (array[middleIndex] < key) {
            startIndex = middleIndex + 1;
        } else {
            endIndex = middleIndex - 1;
        }
    }

    return -1;
}

int main() {
    int size = 10;
    int array[size];
    int key;

    /*=============== Input ====================*/
    printf("Enter the key to search: ");
    scanf("%d", &key);

    printf("Enter %d numbers:\n", size);
    for (int i = 0; i < size; i++) {
        printf("Data %d: ", i + 1);
        scanf("%d", &array[i]);
    }
    /*=============== Input ====================*/

    /*=============== Output ====================*/
    insertionSort(array, size);
    printf("\nSorted data: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }

    int index = binarySearch(array, size, key);
    if (index != -1) {
        printf("\nKey %d found at index %d", key, index);
    } else {
        printf("\nKey %d not found", key);
    }
    /*=============== Output ====================*/

    printf("\n");
    return 0;
}
