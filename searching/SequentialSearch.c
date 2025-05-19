#include "stdio.h"

int sequentialSearch(int array[], int size, int key) {
    int index = 0;
    int indexAkhir = size - 1;

    while (index <= indexAkhir) {
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
    printf("Masukkan key: ");
    scanf("%d", &key);

    printf("Masukkan data\n");
    for (int i = 0; i < size; ++i) {
        printf("Data ke-%d: ", i + 1);
        scanf("%d", &array[i]);
    }
    /*====================== Input ======================*/


    /*====================== Output ======================*/
    printf("\nData yang telah dimasukkan: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }

    int index = sequentialSearch(array, size, key);
    if (index != -1) {
        printf("\nKey %d telah ditemukan di Index ke %d", key, sequentialSearch(array, size, key));
    } else {
        printf("\nKey %d tidak di temukan", key);
    }
    /*====================== Output ======================*/

    return 0;
}