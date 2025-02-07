#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Comparator function for qsort
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// Recursive function to generate binary codes
void assignBinaryCodes(int arr[], char codes[][100], int index, char* prefix) {
    if (index < 0) {
        return;
    }
    // Assign the prefix to the current index
    strcpy(codes[index], prefix);
    // Add '0' and '1' recursively
    char leftPrefix[100], rightPrefix[100];
    sprintf(leftPrefix, "%s0", prefix);
    sprintf(rightPrefix, "%s1", prefix);
    assignBinaryCodes(arr, codes, index - 1, leftPrefix);
    assignBinaryCodes(arr, codes, index - 2, rightPrefix);
}

int main() {
    int arr[] = {5, 9, 12, 13, 16, 45}; // Example array
    int size = sizeof(arr) / sizeof(arr[0]);
    char codes[size][100]; // Array to store binary codes

    // Sort the array using qsort
    qsort(arr, size, sizeof(int), compare);

    // Combine elements recursively until size == 1
    while (size > 1) {
        // Combine the smallest two elements
        int sum = arr[0] + arr[1];
        for (int i = 2; i < size; i++) {
            arr[i - 2] = arr[i];
        }
        size -= 1;
        arr[size - 1] = sum;

        // Sort the array again
        qsort(arr, size, sizeof(int), compare);
    }

    // Assign binary codes
    assignBinaryCodes(arr, codes, size - 1, "");

    // Print the binary codes
    printf("Binary codes:\n");
    for (int i = 0; i < size; i++) {
        printf("%d: %s\n", arr[i], codes[i]);
    }

    return 0;
}
