sentence = raw_input('Enter the sentence: ')
word = raw_input('Enter the word: ')

arr = sentence.split()
count = 0

for temp in arr:
    if temp == word:
        count += 1

print('number of matching string: {}'.format(count))