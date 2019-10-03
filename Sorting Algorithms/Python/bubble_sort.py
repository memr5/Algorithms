
def bubble_sort(a):
    """Bubble sort"""

    for _ in range(len(a)):
        for i in range(1, len(a)):
            if a[i] < a[i-1]:
                temp = a[i]
                a[i] = a[i-1]
                a[i-1] = temp

if __name__ == '__main__':
    arr = [10, 4, 8, 4, 9, 3, 0]
    print(arr)
    bubble_sort(arr)
    print(arr)