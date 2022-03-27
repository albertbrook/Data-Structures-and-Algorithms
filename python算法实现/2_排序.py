def selection_sort(arr):
    for i in range(len(arr) - 1):
        for j in range(i + 1, len(arr)):
            if arr[i] > arr[j]:
                (arr[i], arr[j]) = (arr[j], arr[i])
    return arr


def bubble_sort(arr):
    for i in range(len(arr) - 1, 0, -1):
        for j in range(i):
            if arr[j] > arr[j + 1]:
                (arr[j], arr[j + 1]) = (arr[j + 1], arr[j])
    return arr


if __name__ == '__main__':
    print(selection_sort([4, 5, 1, 3, 2]))
    print(bubble_sort([4, 5, 2, 3, 1]))
