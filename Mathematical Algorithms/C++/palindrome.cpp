//tells if the given no. is a palindrome or not
// contributed by Arpit Godghate
// Github: @arpitg24
#include<iostream>
using namespace std;
int main(){
    string num;
    cin>>num;
    int length = num.length();
    int count = 0;
    for(int i = 0;i<length;i++){
        if(num[i]==num[length-i-1]){
            count++;
        }
    }
    bool palindrome = false;
    if(count==length){
        palindrome = true;
    }
    if(palindrome == true){
        cout<<"This number is a palindrome";
    }else{
        cout<<"This number is NOT a palindrome";
    }
}
