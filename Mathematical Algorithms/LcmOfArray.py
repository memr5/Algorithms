# find LCM of n elements 

# Base Function to find LCM of given 2 numbers
def find_lcm(num1, num2): 

    # num - numerator and den - denominator

    if(num1>num2): 
        num = num1 
        den = num2 
    else: 
        num = num2 
        den = num1 
    
    # rem - remainder
    rem = num % den 
    
    # Iteratively re-evaluation of arguments num, den, rem till rem == 0
    while(rem != 0): 
        num = den 
        den = rem 
        rem = num % den 
    
    # when rem == 0, resultant den => GCD
    gcd = den 

    # Property of GCD*LCM = num1*num2
    lcm = int(int(num1 * num2)/int(gcd)) 

    return lcm 

# sample Case      
l = [2, 7, 3, 9, 4] 
  
# initalisation of LCM of first 2 elements (Driver Code)
num1 = l[0] 
num2 = l[1] 

lcm = find_lcm(num1, num2) 

# Iteratively Builting over the previously calculated LCM of first 2 elements of array  
for i in range(2, len(l)): 
    lcm = find_lcm(lcm, l[i]) 

# Final LCM of the Array      
print(lcm) 