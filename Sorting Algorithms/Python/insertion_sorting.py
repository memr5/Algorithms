# Insertion sorting Algorithm
# @python

def insertion_sort(list_):

    for x in range(1, len(list_)):
        cursor = list_[x]
        pos = x

        while pos > 0 and list_[pos - 1] > cursor:
            list_[pos] = list_[pos - 1]
            pos = pos - 1
        list_[pos] = cursor
    return list_

array = [15, 2, 4, 50, 30, 2, 0, 1, 4]
sorted = insertion_sort(array)
print(sorted)
