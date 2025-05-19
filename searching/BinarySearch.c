#include "stdio.h"

void bubbleSort(int array[], int size) {
    for(int i = 0; i < size-1; i++) {
        int swapped = 0;
        for(int j = 0; j < size-i-1; j++) {
            if(array[j] > array[j+1]) {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
                swapped = 1;
            }
        }
        if(!swapped) break;
    }
}

int binarySearch(int array[], int size, int key) {
    int indexAwal = 0;
    int indexAkhir = size - 1;

    while (indexAwal <= indexAkhir) {
        int indexTengah = array[(indexAwal + indexAkhir) / 2];

        if (indexTengah < key) {
            indexAkhir = indexTengah - 1;
        } else {
            indexAwal = indexTengah + 1;
        }

        if (indexTengah == key) {
            return indexTengah;
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
    bubbleSort(array, size);
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