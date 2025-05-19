#include <stdio.h>

void ascendingSort(int array[], int size) {
    int sortedArray[size];
    int comparisons = 0, swaps = 0;

    for(int i = 0; i < size; i++) {
        sortedArray[i] = array[i];
    }

    for (int i = 0; i < size - 1; i++) {
        int min_idx = i;

        for (int j = i + 1; j < size; j++) {
            comparisons++;
            if (sortedArray[j] < sortedArray[min_idx]) {
                min_idx = j;
            }
        }

        if (min_idx != i) {
            int temp = sortedArray[i];
            sortedArray[i] = sortedArray[min_idx];
            sortedArray[min_idx] = temp;
            swaps++;
        }
    }

    for(int i = 0; i < size; i++) {
        printf("%d ", sortedArray[i]);
    }

    printf("\nTotal comparison: %d", comparisons);
    printf("\nTotal swap: %d\n", swaps);
}

void descendingSort(int array[], int size) {
    int sortedArray[size];
    int comparisons = 0, swaps = 0;

    for(int i = 0; i < size; i++) {
        sortedArray[i] = array[i];
    }

    for (int i = 0; i < size - 1; i++) {
        int max_idx = i;

        for (int j = i + 1; j < size; j++) {
            comparisons++;
            if (sortedArray[j] > sortedArray[max_idx]) {
                max_idx = j;
            }
        }

        if (max_idx != i) {
            int temp = sortedArray[i];
            sortedArray[i] = sortedArray[max_idx];
            sortedArray[max_idx] = temp;
            swaps++;
        }
    }

    for(int i = 0; i < size; i++) {
        printf("%d ", sortedArray[i]);
    }

    printf("\nTotal comparison: %d", comparisons);
    printf("\nTotal swap: %d\n", swaps);
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

    printf("\n\nSelection Sort (ascending): ");
    ascendingSort(array, maxInput);

    printf("\nSelection Sort (descending): ");
    descendingSort(array, maxInput);

    printf("\n");
    return 0;
}
