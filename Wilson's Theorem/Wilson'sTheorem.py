def factorial(x):
	if x == 0:
		return(1)
	else:
		total = 1
		while(x>0):
			total *= x
			x -= 1
		return(total)
		
def wilson(x):
	if(factorial(x-1)%x==(x-1) and x!=1):
		return(1)
	else:
		return(0)

def main():
    a = input("Enter the range in which prime numbers are to be printed. \nEnter a,b for the range [a,b], where a and b are two integers. \n")
    b = a.split(",")
    c = int(b[0])
    d = int(b[1])
    print("\nThe prime numbers in the inclusive range [{0},{1}] are as follows.".format(c,d))
    for i in range(c,d+1):
        if(wilson(i)==1):
            print(i)

main()