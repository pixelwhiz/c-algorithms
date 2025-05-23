#include <stdio.h>

void ascendingSort(int array[], int size) {
    int sortedArray[size];
    int comparisons = 0, shifts = 0, insertions = 0;

    for(int i = 0; i < size; i++) {
        sortedArray[i] = array[i];
    }

    for(int i = 1; i < size; i++) {
        int key = sortedArray[i];
        int j = i - 1;

        while(j >= 0 && sortedArray[j] > key) {
            comparisons++;
            sortedArray[j + 1] = sortedArray[j];
            shifts++;
            j--;
        }

        if (j >= 0) comparisons++;

        sortedArray[j + 1] = key;
        insertions++;
    }

    for(int i = 0; i < size; i++) {
        printf("%d ", sortedArray[i]);
    }

    printf("\nTotal comparison: %d", comparisons);
    printf("\nTotal shift: %d", shifts);
    printf("\nTotal insertion: %d\n", insertions);
}

void descendingSort(int array[], int size) {
    int sortedArray[size];
    int comparisons = 0, shifts = 0, insertions = 0;

    for(int i = 0; i < size; i++) {
        sortedArray[i] = array[i];
    }

    for(int i = 1; i < size; i++) {
        int key = sortedArray[i];
        int j = i - 1;

        while(j >= 0 && sortedArray[j] < key) {
            comparisons++;
            sortedArray[j + 1] = sortedArray[j];
            shifts++;
            j--;
        }

        if (j >= 0) comparisons++;

        sortedArray[j + 1] = key;
        insertions++;
    }

    for(int i = 0; i < size; i++) {
        printf("%d ", sortedArray[i]);
    }

    printf("\nTotal comparison: %d", comparisons);
    printf("\nTotal shift: %d", shifts);
    printf("\nTotal insertion: %d\n", insertions);
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

    printf("\n\nInsertion Sort (ascending): ");
    ascendingSort(array, maxInput);

    printf("\nInsertion Sort (descending): ");
    descendingSort(array, maxInput);

    return 0;
}
