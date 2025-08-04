#include <stdio.h>
#include <string.h>

#define MAX_INPUT 10

void ascendingSort(int array[], int low, int high);
void descendingSort(int array[], int low, int high);

void ascendingSort(int array[], int low, int high) {
    if (low < high) {
        int pivot = array[high];
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (array[j] < pivot) {
                i++;
                int temp = array[i]; array[i] = array[j]; array[j] = temp;
            }
        }

        int temp = array[i + 1]; array[i + 1] = array[high]; array[high] = temp;
        int pi = i + 1;

        ascendingSort(array, low, pi - 1);
        ascendingSort(array, pi + 1, high);
    }
}

void descendingSort(int array[], int low, int high) {
    if (low < high) {
        int pivot = array[high];
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (array[j] > pivot) {
                i++;
                int temp = array[i]; array[i] = array[j]; array[j] = temp;
            }
        }

        int temp = array[i + 1]; array[i + 1] = array[high]; array[high] = temp;
        int pi = i + 1;

        descendingSort(array, low, pi - 1);
        descendingSort(array, pi + 1, high);
    }
}

int main() {
    char buffer[100];
    int array[MAX_INPUT];

    printf("Enter %d integer numbers:\n", MAX_INPUT);
    for (int i = 0; i < MAX_INPUT; ++i) {
        while (1) {
            printf("Input %d: ", i + 1);
            fgets(buffer, sizeof(buffer), stdin);
            buffer[strcspn(buffer, "\n")] = '\0';

            if (sscanf(buffer, "%d", &array[i]) == 1) {
                break;
            } else {
                printf("Invalid input. Please enter an integer.\n");
            }
        }
    }

    printf("\nEntered input: ");
    for (int i = 0; i < MAX_INPUT; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    int ascArray[MAX_INPUT], descArray[MAX_INPUT];
    memcpy(ascArray, array, sizeof(array));
    memcpy(descArray, array, sizeof(array));

    printf("\nQuick Sort (ascending): ");
    ascendingSort(ascArray, 0, MAX_INPUT - 1);
    for (int i = 0; i < MAX_INPUT; i++) {
        printf("%d ", ascArray[i]);
    }

    printf("\nQuick Sort (descending): ");
    descendingSort(descArray, 0, MAX_INPUT - 1);
    for (int i = 0; i < MAX_INPUT; i++) {
        printf("%d ", descArray[i]);
    }

    printf("\n");
    return 0;
}
