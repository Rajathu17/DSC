#include <stdio.h>

// Recursive Binary Search function
int binarySearch(int arr[], int low, int high, int target) {
    if (low <= high) {
        int mid =(high + low) / 2;

        // If the element is present at the middle
        if (arr[mid] == target)
            return mid;

        // If the element is smaller than mid, it can only be present in the left subarray
        if (arr[mid] > target)
            return binarySearch(arr, low, mid - 1, target);

        // Else the element can only be present in the right subarray
        return binarySearch(arr, mid + 1, high, target);
    }

    // Element is not present in the array
    return -1;
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 10;
    int result = binarySearch(arr, 0, n - 1, target);
    if (result == -1)
        printf("Element is not present in array\n");
    else
        printf("Element is present at index %d\n", result);
    return 0;
}
