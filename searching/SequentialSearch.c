#include "stdio.h"

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

    
    /*====================== Output ======================*/

    return 0;
}