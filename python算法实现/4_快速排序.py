import random


def quick_sort(array):
    if len(array) < 2:
        return array
    pivot = array.pop(random.randint(0, len(array) - 1))
    less = [i for i in array if i <= pivot]
    greater = [i for i in array if i > pivot]
    return quick_sort(less) + [pivot] + quick_sort(greater)


if __name__ == '__main__':
    print(quick_sort([4, 5, 2, 3, 1]))
