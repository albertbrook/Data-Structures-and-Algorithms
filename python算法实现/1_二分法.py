def binary_search(list, item):
    low = count = 0
    high = len(list) - 1
    value = None
    while low <= high:
        count += 1
        mid = (low + high) // 2
        if list[mid] < item:
            low = mid + 1
        elif list[mid] > item:
            high = mid - 1
        else:
            value = mid
            break
    print("查找次数：%d" % count)
    return value


if __name__ == '__main__':
    my_list = [i for i in range(1, 11)]
    print(my_list)
    while True:
        try:
            value = binary_search(my_list, int(input("item = ")))
        except Exception as e:
            print(e)
            continue
        print("索引值：%d" % value if value is not None else "没有找到")
