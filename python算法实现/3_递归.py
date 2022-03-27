def factorial(n):
    if n < 0:
        return None
    elif n == 0:
        return 1
    return n * factorial(n - 1)


if __name__ == '__main__':
    while True:
        try:
            print(factorial(int(input("n = "))))
        except Exception as e:
            print(e)
