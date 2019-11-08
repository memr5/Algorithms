def stringReverse(str):
    i = len(str)
    i = i - 1
    res = ""
    while i >= 0:
        res += str[i]
        i = i - 1
    return res

def findHash(pattern):
    val = 0
    patternReverse = stringReverse(pattern)
    for i in range(0, len(patternReverse)):
        val = val + (letterMap[patternReverse[i]] * (10 ** i))
    return val

def extractString(text, startIndex, endIndex):
    extractedString = ""
    i = startIndex
    j = 0
    while j < endIndex:
        extractedString += text[i]
        i = i + 1
        j = j + 1
    return extractedString

def compareStrings(source, target):
    for i in range(0, len(source)):
        if source[i] != target[i]:
            return False
    return True


def rabinKarp(text, pattern):
    text = text.lower()
    pattern = pattern.lower()
    hashPattern = findHash(pattern)
    patternFound = False
    index=[]
    spuriousHits = 0
    for i in range(0, len(text) - len(pattern)):
        subString = extractString(text, i, len(pattern))
        subStringHash = findHash(subString)
        if (subStringHash == hashPattern):
            matched = compareStrings(subString, pattern)
            if( matched == True):
                patternFound = True
                index.append(i)     
            else:
                spuriousHits += 1
        else: 
            i = i + 1

    if patternFound == True:
        print("Pattern Found at index: ", index)
        print("Number of spurious hits: ", spuriousHits)
    else: 
        print("Pattern not Found!!!")



text = "hello and world"
pattern = "lo"

letterMap = {'a': 1, 'b': 2, 'c': 3, 'd': 4, 'e': 5, 'f': 6, 'g': 7, 'h': 8, 'i': 9, 'j': 10, 'k': 11 , 'l': 12, 'm': 13, 'n': 14, 'o': 15, 'p': 16, 'q': 17, 'r': 18, 's': 19, 't': 20, 'u': 21, 'v': 22, 'w': 23, 'x': 24,     'y': 25, 'z': 26, ' ': 27}

rabinKarp(text, pattern)