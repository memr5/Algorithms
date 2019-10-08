stack = []

string = str(input("Write one word:"))

i=len(string.replace(" ", ""))-1
while i>=0:
    if string[i] != " ":
        stack.append(string[i])
        i=i-1

stringBackwards = ""
for i in range(len(string)):
    stringBackwards = stringBackwards+stack[i]

if string == stringBackwards:
    print("is palindrome")
else:
    print("isnt palindrome")    

input("Press enter to exit")