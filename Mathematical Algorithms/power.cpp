// C++ Program for finding power of a number in log N time
#include<bits/stdc++.h>
using namespace std;

int power(int x,int n)
{
    int result=1;
    while(n)
    {
        if(n % 2 == 1)
            result *= x;
        x *= x;
        n /= 2;
    }
    return result;
}

int main(){
    cout<<power(20,5);
    return 0;
}
