// A cpp program to demonstrate Ceaser Cipher algorithm 

#include <bits/stdc++.h>
using namespace std;

string ceaserCipher(string input, int key){
  int len = input.length();
  string encrypt = "";
  for(int i=0;i<len;i++){
    if(isalpha(input[i])){ // Checking for alphabets
      if(isupper(input[i])){ // Checking if character is in Uppercase
        int value = input[i] - 'A'; // Converting between 0-26
        int addKey = (value + key)%26; // Adding key and modding it with 26
        int asciiValue = addKey + 'A'; // Converting back to ascii value
        encrypt += char(asciiValue);
      }else{ // character in lower case
        int value = input[i] - 'a';
        int addKey = (value + key)%26;
        int asciiValue = addKey + 'a';
        encrypt += char(asciiValue);
      }
    }else{ // Other than alphabets
      encrypt += input[i];
    }
  }
  return encrypt;
}

int main() {
  string input, encrypt;
  cout<<"Enter string to encrypt : ";
  cin>>input;
  int key;
  cout<<"Enter key : ";
  cin>>key;
  encrypt = ceaserCipher(input, key);
  cout<<"Encrypted String is : "<<encrypt;
  return 0;
}