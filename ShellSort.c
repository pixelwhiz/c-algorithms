#include <stdio.h>

void ascendingSort(int array[], int size) {
    int sortedArray[size];
    for(int i = 0; i < size; i++) {
        sortedArray[i] = array[i];
    }

    for(int gap = size/2; gap > 0; gap /= 2) {
        for(int i = gap; i < size; i++) {
            int temp = sortedArray[i];
            int j;

            for(j = i; j >= gap && sortedArray[j - gap] > temp; j -= gap) {
                sortedArray[j] = sortedArray[j - gap];
            }
            sortedArray[j] = temp;
        }
    }

    for(int i = 0; i < size; i++) {
        printf("%d ", sortedArray[i]);
    }
}

int main() {
    int array[10];
    int maxInput = 10;

    printf("Masukkan 10 bilangan integer: \n");
    for(int i = 0; i < maxInput; i++) {
        printf("Input ke-%d: ", i + 1);
        scanf("%d", &array[i]);
    }

    printf("\nInput yang anda masukkan: ");
    for(int i = 0; i < maxInput; i++) {
        printf("%d ", array[i]);
    }

    printf("\n\nShell Sort (ascending): ");
    ascendingSort(array, maxInput);

    printf("\n");
    return 0;
}