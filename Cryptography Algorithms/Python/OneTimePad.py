import string
import random

key = ''
encrypted_text = []
bin_key = []

def bin_to_str(binary):
    binary = str(binary)
    character = ''
    char = ''
    size = len(binary)
    k = 1
    for j in binary:
        if j != ' ':
            character += j
            if k == size:
                char += chr(int(character, 2))
        else:
            char += chr(int(character, 2))
            character = ''
        k += 1        
    return char

def str_to_bin(string):
    binary = ''
    for i in string:
        binary += bin(ord(i))[2::] + ' '
    return binary

def print_layout_name(name):
    print("\n+==================================================================+")
    print("  ",name,"\n+==================================================================+")

def print_menu():
    print_layout_name("ONE-TIME PAD")
    print("\n  1 - Encrypt\n  2 - Decrypt\n  0 - Exit\n")    

def generator_key(size):
    return ''.join(random.choice(string.ascii_letters) for x in range(size))

def select_option(option):
    if option == 1:  
        encrypt()    
    if option == 2:
        decrypt()
    if option == 0:
        exit(0)

def encrypt_with_a_key(key, text):
    bits_key = key.split(' ')
    bits_text = text.split(' ')
    del(bits_key[-1])
    del(bits_text[-1])
    result = []
    for i in range(len(bits_text)):
        result.append( str( bin( int(bits_text[i],2) ^ int(bits_key[i],2) )[2::] ) )
    return result

def encrypt():
    global key, binary_key, encrypted_text, bin_key    
    plain_text = str(input("  Enter the plain text: "))        
    binary_text = str_to_bin(plain_text)
    key = generator_key(len(plain_text))
    print("\n  Key: ", key)
    binary_key = str_to_bin(key)
    print("\n  Binary Key: ", binary_key)
    encrypted_text = encrypt_with_a_key(binary_key, binary_text)
    bin_key = binary_key.split(' ')
    del(bin_key[-1])    
    print("\n  Encrypted Message: ", encrypted_text)    

def decrypt():
    global key, bin_key, encrypted_text
    plain_text = []
    decrypted_text = []    
    if(key != ''):
        print("\n  Binary Plain Text: ", end="")
        for i in range( len(encrypted_text) ):
            decrypted_text.append( bin( int(bin_key[i],2) ^ int(encrypted_text[i],2) )[2::] )
            print(decrypted_text[i], " " ,end="")
        print("\n\n  Decrypted Message: ", end="")
        for j in range(len(decrypted_text)):
            plain_text.append( bin_to_str( decrypted_text[j] ))
            print(plain_text[j], end="" )
        print("\n")        
    else:
        print("\n  No keys stored in memory")

def main():
    print_menu()
    option = int(input("  Select an option: "))
    select_option(option)
    while(option != 0): 
        print_menu()    
        option = int(input("  Select an option: "))
        select_option(option)

main()
