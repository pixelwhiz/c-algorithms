#include <stdio.h>
#include <string.h>

void ascendingSort(int array[], int size);
void descendingSort(int array[], int size);

void mergeAscending(int array[], int left, int mid, int right);
void mergeDescending(int array[], int left, int mid, int right);


void mergeAscending(int array[], int left, int mid, int right) {
    int leftSize = mid - left + 1;
    int rightSize = right - mid;
    int L[leftSize], R[rightSize];

    for (int i = 0; i < leftSize; i++)
        L[i] = array[left + i];
    for (int j = 0; j < rightSize; j++)
        R[j] = array[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < leftSize && j < rightSize) {
        if (L[i] <= R[j])
            array[k++] = L[i++];
        else
            array[k++] = R[j++];
    }

    while (i < leftSize)
        array[k++] = L[i++];
    while (j < rightSize)
        array[k++] = R[j++];
}

void mergeSortAscending(int array[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSortAscending(array, left, mid);
        mergeSortAscending(array, mid + 1, right);
        mergeAscending(array, left, mid, right);
    }
}

void ascendingSort(int array[], int size) {
    mergeSortAscending(array, 0, size - 1);
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);
}

void mergeDescending(int array[], int left, int mid, int right) {
    int leftSize = mid - left + 1;
    int rightSize = right - mid;
    int L[leftSize], R[rightSize];

    for (int i = 0; i < leftSize; i++)
        L[i] = array[left + i];
    for (int j = 0; j < rightSize; j++)
        R[j] = array[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < leftSize && j < rightSize) {
        if (L[i] >= R[j])
            array[k++] = L[i++];
        else
            array[k++] = R[j++];
    }

    while (i < leftSize)
        array[k++] = L[i++];
    while (j < rightSize)
        array[k++] = R[j++];
}

void mergeSortDescending(int array[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSortDescending(array, left, mid);
        mergeSortDescending(array, mid + 1, right);
        mergeDescending(array, left, mid, right);
    }
}

void descendingSort(int array[], int size) {
    mergeSortDescending(array, 0, size - 1);
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);
}



int main() {
    char buffer[100];
    const int maxInput = 10;
    int array[maxInput];

    printf("Enter 10 integer numbers:\n");
    for (int i = 0; i < maxInput; ++i) {
        while (1) {
            printf("Input %d: ", i + 1);
            fgets(buffer, sizeof(buffer), stdin);
            buffer[strcspn(buffer, "\n")] = '\0';

            if (sscanf(buffer, "%d", &array[i]) == 1) {
                break;
            }

        }
    }

    printf("\nEntered input: ");
    for (int i = 0; i < maxInput; ++i) {
        printf("%d ", array[i]);
    }

    printf("\n\nMerge Sort (ascending): ");
    ascendingSort(array, maxInput);

    printf("\n\nMerge Sort (descending): ");
    descendingSort(array, maxInput);

    printf("\n");
    return 0;
}
