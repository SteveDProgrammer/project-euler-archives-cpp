/*
Smallest Multiple
Problem 5

2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
*/

#define bigint long long int
#include <iostream>
using namespace std;

// GCD of 1-20 is 1, but we can't consider GCD of all nums from 1-20 at once
// because the LCM = a*b/GCD(a, b) formula only deals with two numbers at a time 

bigint gcd(bigint dividend, bigint divisor) 
{
    if(dividend % divisor == 0) return divisor;
    int new_divisor = dividend % divisor; //remainder becomes the new divisor
    int new_dividend = divisor;           //previous devisor becomes the dividend
    return gcd(new_dividend, new_divisor);
}

bigint lcm(bigint a, bigint b)
{
    return a*b/gcd(a, b);
}

int main()
{
    bigint lcmResult = 1;
    for(bigint i = 11; i <= 20; i++)
    {
        lcmResult = lcm(lcmResult, i);
    }
    cout<<lcmResult;
    return 0;
}