/*
Largest Prime Factor

Problem 3

The prime factors of 13195 are 5, 7, 13 and 29.
What is the largest prime factor of the number 600851475143?

HINT :- There can't be two factors of a number greater than the square root of the number.
If there are, then that would result in a number greater than the original number which is a contradiction.

ANALOGY:

- Consider the number to be Area of a Rectangle, and factors a & b to be the sides
- That would give us a square if a = b = sqrt(number)
- If a = b, we can't increase both a and b without changing the area of the rectangle
- Hence, all other value of a and b will be less than sqrt(number)
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