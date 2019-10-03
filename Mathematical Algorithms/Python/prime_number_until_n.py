#Vincent Druesne
#Give you all the prime number until n


n = int(input("Enter n : "))
result = []

for i in range(1,n+1):
    test = True
    for j in range(2,i):
        if(i % j == 0):
            test = False
        if(not test):
            break
    if(test):
        result.append(i)

print(result)
