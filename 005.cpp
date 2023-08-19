/*
Smallest Multiple
Problem 5

2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
*/

#define bigint long long int
#include <iostream>
using namespace std;

bigint gcd(bigint a, bigint b)
{
    bigint temp = 0;
    while(a != 0)
    {
        temp = b % a;
        b = a;
        a = temp;
    }
    return b;
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