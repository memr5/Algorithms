// Sieve of Eratosthenes
#include<bits/stdc++.h>
using namespace std;

vector<int> sieve(int n)
{
    vector<int> prime;
    bool isprime[n];
    for(int p = 2; p < n; p++)
        isprime[p] = true;

    for (int p = 2; p * p < n; p++)
    {
        if (isprime[p] == true)
        {
	         for (int i = p*p; i <= n; i += p)
                isprime[i] = false;
        }
    }
    for (int p = 2; p <= n; p++)
       if (isprime[p] == true){
         prime.push_back(p);
       }
    return prime;
}

int main(){
  int n = 100000;
  vector<int> prime;
  prime = sieve(n);
  for(auto p: prime)
      cout<<p<<" ";

}
