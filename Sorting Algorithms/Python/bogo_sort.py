import random

def bogoSort(x):
	n = len(x)
	while (isSorted(x) == False):
		shuffle(x)

def isSorted(x):
	n = len(x)
	for i in range(0, n-1):
		if (x[i] > x[i+1]):
			return False
	return True

def shuffle(x):
	n = len(x)
	for i in range(0,n):
		r = random.randint(0,n-1)
		x[i], x[r] = x[r], x[i]

#Driver code
x = [4, 2, 3, 33, 12, 1, 20, 21]
bogoSort(x)
for i in range(len(x)):
	print("%d" %x[i])
