#bubble sort algo
def sort_tup(tup):
    lst = len(tup)
    for i in range(0,lst):
        for j in range(0,lst-i-1):
            if (tup[j][1]>tup[j+1][1]):
                tup[j][1],tup[j+1][1] = tup[j+1][1],tup[j][1]
    return tup

#S is starting time of a meating
#F is finishing time of meating

s=[1,3,0,5,8,5]
f=[2,4,6,7,9,9]
result = zip(s,f)
result = sort_tup(result)
last_finish = 0
for i in result:
    if i[0] >= last_finish:
        print(i)
        last_finish = i[1]

