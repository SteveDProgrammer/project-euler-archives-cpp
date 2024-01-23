/*
- Prime numbers have only two divisors
    - 1 and itself

- If n is not prime, then 
    - n = a * b.

- If we keep n constant
    - Increasing a will decrease b, because n = a * b. 

- So, by checking all a <= sqrt(n), we automatically check all corresponding b values.

- If no factors are found then n is a prime number.
*/

#define NUMBER 600851475143

#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int number){
    for (int i = 2; i < sqrt((float)number); i++) 
    {
        if(number%i == 0) return false;
    }
    return true;
}

int main()
{
    int sq_root = sqrt((float)NUMBER);

    for (int i = sq_root; i > 0; i--) 
    {
        if(isPrime(i) && NUMBER % i == 0)
        {
            cout<<i;
            break;
        }
    }
}