# GCD of more than two (or array) numbers 
  
# Function implements the Euclidian algorithm to find H.C.F. of two number 
def find_gcd(x, y): 
    while(y): 
        x, y = y, x % y 
    return x 

# Sample Case
l = [2, 4, 6, 8, 16] 

# initialisation of gcd of first 2 numbers  
num1 = l[0] 
num2 = l[1] 
gcd = find_gcd(num1, num2) 

# building over the initially calculated gcd iteratively
for i in range(2, len(l)): 
    gcd = find_gcd(gcd, l[i]) 

# final output      
print(gcd) 