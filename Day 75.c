#include <stdio.h>
#include <stdlib.h>

// Structure for hash map
typedef struct {
    int key;
    int value;
} Hash;

// Simple hash function
int findIndex(Hash hash[], int size, int key) {
    int index = abs(key) % size;

    while (hash[index].key != 0 && hash[index].key != key) {
        index = (index + 1) % size;
    }
    return index;
}

int maxLenZeroSum(int arr[], int n) {
    Hash hash[2 * n + 1];

    // Initialize hash map
    for (int i = 0; i < 2 * n + 1; i++) {
        hash[i].key = 0;
        hash[i].value = -1;
    }

    int sum = 0, maxLen = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        // Case 1: sum is zero
        if (sum == 0) {
            maxLen = i + 1;
        }

        int index = findIndex(hash, 2 * n + 1, sum);

        // Case 2: sum seen before
        if (hash[index].key == sum) {
            int len = i - hash[index].value;
            if (len > maxLen)
                maxLen = len;
        } 
        // Store first occurrence
        else {
            hash[index].key = sum;
            hash[index].value = i;
        }
    }

    return maxLen;
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("%d\n", maxLenZeroSum(arr, n));

    return 0;
}