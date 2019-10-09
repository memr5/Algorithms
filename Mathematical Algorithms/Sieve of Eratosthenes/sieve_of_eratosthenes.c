#include <stdio.h>
#include <math.h>

#define V_MAX 1000
#define P_MAX 7919

void sieve(int n, int primes[]);

int main(void) {
  
    int i, n, c;
    int v[V_MAX], p[P_MAX], r[P_MAX];

    // Input wanted prime count
    scanf("%d", &n);

    // Read indexes for printing order
    for (i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    // Calculates P_MAX n primes in the array p
    sieve(P_MAX, p);

    // Normalize prime list in another array
    for (i = 0, c = 0; i < P_MAX && c < P_MAX; i++) {
        if (p[i] == 1) {
            r[c] = i;
            c++;
        }
    } 
    
    // Prints a single line with primes sorted by the requested index,
    //  the first prime number (2) is at index 0, and so on.
    for (i = 0; i < n; i++) {
        printf("%d", r[v[i]]);
        if (i < n - 1)
            printf(" ");
        else
            printf("\n");
    }
    
    return 0;
}

void sieve(int n, int primes[]) {
    int i, j;

    for (i = 0; i < n; i++) {
        // we initialize the sieve list to all 1's (True)
        primes[i] = 1;
    }

    // Set the first two numbers (0 and 1) to 0 (False)
    primes[0] = 0, primes[1] = 0;

    // loop through all the numbers up to the sqrt(n)
    for (i = 2; i < sqrt(n); i++){
        // mark off each factor of i by setting it to 0 (False)
        for (j = i * i; j < n; j += i) {
            primes[j] = 0;
        }
    } 
}
