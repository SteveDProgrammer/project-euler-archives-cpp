/*
- Prime numbers have only two divisors
    - 1 and itself

- If n is not prime: 
    - Then n = a * b
    
    - If a = b
        - Then n = sqrt(n) * sqrt(n)
        - sqrt(n) is the midpoint of all factors
    
    - Increasing a will decrease b, because n = a * b
        - Increase a, then a > b
        - Then b < sqrt(n) < a
        - So, on checking all nums <= sqrt(n), we're guranteed to reach b which is a factor
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