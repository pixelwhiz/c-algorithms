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
    int indexAwal = 0;
    int indexAkhir = size - 1;

    while (indexAwal <= indexAkhir) {
        int indexTengah = (indexAwal + indexAkhir) / 2;

        if (array[indexTengah] == key) {
            return indexTengah;
        } else if (array[indexTengah] < key) {
            indexAwal = indexTengah + 1;
        } else {
            indexAkhir = indexTengah - 1;
        }
    }

    return -1;
}


int main() {
    int size = 10;
    int array[size];
    int key;

    /*=============== Input ====================*/
    printf("Masukkan key: ");
    scanf("%d", &key);

    printf("Masukkan Data \n");
        for (int i = 0; i < size; i++) {
            printf("Data ke-%d: ", i + 1);
            scanf("%d", &array[i]);
    }
    /*=============== Input ====================*/



    /*=============== Output ====================*/
    insertionSort(array, size);
    printf("\nData yang telah dimasukkan dan disorting: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }

    int index = binarySearch(array, size, key);
    if (index != -1) {
        printf("\nKey %d telah ditemukan di Index ke %d", key, binarySearch(array, size, key));
    } else {
        printf("\nKey %d tidak di temukan", key);
    }
    /*=============== Output ====================*/


    printf("\n");
    return 0;
}