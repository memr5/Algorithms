#include <stdio.h>

int factorial (int x) {
    if (x == 0)
        return 1;
    else {
        int y = 1;
        while (x > 0) {
            y *= x;
            x --;
        }
        return y;
    }
}

int is_prime (int x) {
    if ((factorial(x - 1) % x == (x - 1)) && (x != 1)) {
        return 1;
    }
    else
    {
        return 0;
    }
    
}

int main ()
{
    int a, b;
    scanf("%d%d",&a, &b);
    printf("Prime numbers in the inclusive range [%d,%d] are:\n", a, b);
    for (int i = a; i <= b; i++) {
        if (is_prime(i) == 1)
            printf("%d\n", i);
    }
    return 0;
}
