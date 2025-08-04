#include <stdio.h>

void ascendingSort(int array[], int size) {
    int sortedArray[size];
    for(int i = 0; i < size; i++) {
        sortedArray[i] = array[i];
    }

    for(int i = 0; i < size-1; i++) {
        int swapped = 0;

        for(int j = 0; j < size-i-1; j++) {
            if(sortedArray[j] > sortedArray[j+1]) {
                int temp = sortedArray[j];
                sortedArray[j] = sortedArray[j+1];
                sortedArray[j+1] = temp;
                swapped = 1;
            }
        }

        if(swapped == 0) {
            break;
        }
    }

    for(int i = 0; i < size; i++) {
        printf("%d ", sortedArray[i]);
    }
}

int main() {
    int array[10];
    int maxInput = 10;

    printf("Enter 10 integer number: \n");
    for (int i = 0; i < maxInput; i++) {
        printf("Input %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    printf("\nEntered input: ");
    for (int i = 0; i < maxInput; i++) {
        printf("%d ", array[i]);
    }

    printf("\n\nBubble Sort (ascending): ");
    ascendingSort(array, maxInput);

    printf("\n");
    return 0;
}
