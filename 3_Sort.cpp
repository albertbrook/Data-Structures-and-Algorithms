#include <bits/stdc++.h>

using namespace std;

bool check(void (*mySort)(int *, int)) {
    int arr1[1000];
    int arr2[1000];

    srand((int) time(0));
    for (int &i : arr1)
        i = rand() % 2000 - 1000;
    memcpy(arr2, arr1, sizeof(arr1));

    sort(arr1, arr1 + 1000);
    mySort(arr2, 1000);

    for (int i = 0; i < 1000; ++i)
        if (arr1[i] != arr2[i])
            return false;
    return true;
}

void print(void (*mySort)(int *, int), int *arr, int len) {
    cout << (check(mySort) ? "true" : "false");

    int copy[len];
    memcpy(copy, arr, sizeof(int) * len);
    mySort(copy, len);

    for (int i = 0; i < len; ++i)
        cout << " " << copy[i];
    cout << endl;
}

void swap(int *arr, int pos1, int pos2) {
    int t = arr[pos1];
    arr[pos1] = arr[pos2];
    arr[pos2] = t;
}

void bubble(int *arr, int len) {
    for (int i = len - 1; i > 0; --i)
        for (int j = 0; j < i; ++j)
            if (arr[j] > arr[j + 1])
                swap(arr, j, j + 1);
}

void selection(int *arr, int len) {
    int minPos;
    for (int i = 0; i < len - 1; ++i) {
        minPos = i;
        for (int j = i + 1; j < len; ++j)
            if (arr[j] < arr[minPos])
                minPos = j;
        swap(arr, i, minPos);
    }
}

void insertion(int *arr, int len) {
    for (int i = 1; i < len; ++i)
        for (int j = i; j > 0 && arr[j] < arr[j - 1]; --j)
            swap(arr, j, j - 1);
}

void quickSort(int *arr, int l, int r) {
    if (l >= r)
        return;
    int ll = l, lr = r;
    while (l != r) {
        while (arr[r] >= arr[ll] && l != r)
            r--;
        while (arr[l] <= arr[ll] && l != r)
            l++;
        if (l != r)
            swap(arr, l, r);
    }
    swap(arr, ll, l);
    quickSort(arr, ll, l - 1);
    quickSort(arr, r + 1, lr);
}

void quick(int *arr, int len) {
    quickSort(arr, 0, len - 1);
}

int main() {
    int arr[] = {5, 2, 4, 1, 3};
    int len = sizeof(arr) / sizeof(int);

    print(bubble, arr, len);
    print(selection, arr, len);
    print(insertion, arr, len);
    print(quick, arr, len);

    return 0;
}