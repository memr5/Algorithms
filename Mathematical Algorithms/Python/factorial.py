# Find the factorial of a given number
def factorial(n):
    return 1 if (n == 1 or n == 0) else n * factorial(n - 1)


factorial(5)  # 120
factorial(11)  # 39916800
