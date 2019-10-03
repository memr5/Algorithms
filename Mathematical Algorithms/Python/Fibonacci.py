amount_of_terms = int(input('How many terms of Fibonacci sequence do you want?: '))
i = 0
fibo = []


while i < amount_of_terms:
    if i == 0: term = 0
    elif i == 1: term = 1
    elif i == 2: term = 1
    else:
        term = fibo[i-1]+fibo[i-2]

    fibo.append(term)
    i += 1

for k in fibo:
    print (k, end = ' ')
