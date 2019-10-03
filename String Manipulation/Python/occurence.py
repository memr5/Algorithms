#  Count the number of occurences in a string given by the user after a prompt.
#  Attain the user input and store into a global variable
print("Enter the text you would like to count: ")

#  initialize the variable input to save the text.
words =  input()

#  this will record the input for the newly created variable "words"
print(words)

#  Create a dictionary to store the string 
collection = {}

#  Use a for loop for the characters input by the user, including whitespace (this is case sensitive)
for i in words:
    if i in collection:
        collection[i] +=1
    else:
        collection[i]  =1

#  print results, use a newline break to keep the dictionary on a seperate line of the message.
print("Count of all the characters in your text were the following: \n "
                                                                    + str(collection))