# Python program to sort array 
# of elements using Bucket Sort

# Insertion sort algo
def ins_sort_algorithm(elem):
    for i in range(1, len(elem)):
        j = i-1
        inc = elem[i]
        while j >= 0 and elem[j] > inc:
             elem[j+1] = elem[j]
             j -= 1
        elem[j+1] = inc
    return elem

# Bucket sort algo
def bucket_sort_algorithm(val_list):
    temp = []
    slot = 8 # customizable
    # add empty lists to temp(_arr)
    for i in range(slot):
        temp.append([])
    # Computing
    for j in val_list:
        index_b = int(slot * j)
        temp[index_b].append(j)

    for i in range(slot):
        temp[i] = ins_sort_algorithm(temp[i])

    k = 0
    for i in range(slot):
        for j in range(len(temp[i])):
            val_list[k] = temp[i][j]
            k += 1
    return val_list

# Driver Function
elem_li = [0.1290, 0.2523, 0.0001, 0.91, 0.454, 0.978, 0.01, 0.66]
# Original
print("Before Sorting: ")
print(elem_li)
# Result
print("Result(post-Bucket Sort): ")
print(bucket_sort_algorithm(elem_li))

# Expected Outcome:
# ----------------
# Before Sorting: 
# [0.129, 0.2523, 0.0001, 0.91, 0.454, 0.978, 0.01, 0.66]
# Result(post-Bucket Sort): 
# [0.0001, 0.01, 0.129, 0.2523, 0.454, 0.66, 0.91, 0.978]