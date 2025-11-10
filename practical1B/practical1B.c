#include <stdio.h>
int main() {
    int  n, i, search, start, end, middle;
    int found = 0;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element you want to search: ");
    scanf("%d", &search);
    start = 0;
    end = n - 1;
    while (start <= end) {
        middle = (start + end) / 2;
        if (search == arr[middle]) {
            printf("Element found at index %d\n", middle);
            found = 1;
            break;
        } else if (search > arr[middle]) {
            start = middle + 1;
        } else {
            end = middle - 1;
        }
    }
    if (!found) {
        printf("Element not found in the array.\n");
    }
    return 0;
}