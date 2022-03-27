#include <iostream>

using namespace std;

int binary_search(const int *arr, int len, int item) {
    int low = 0, high = len - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        printf("%d %d %d\n%d %d %d\n\n", low, mid, high, arr[low], arr[mid], arr[high]);
        if (arr[mid] < item)
            low = mid + 1;
        else if (arr[mid] > item)
            high = mid - 1;
        else
            return mid;
    }
    return -1;
}

int main() {
    int arr[] = {1, 3, 5, 7, 9};
    int len = sizeof(arr) / sizeof(int);

    binary_search(arr, len, 3);
    return 0;
}