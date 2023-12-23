/*
 1. (n^2 + n + 41) is prime for [0 <= n <= 39]
 
 2. (n^2 - 79*n + 1601) is prime for [0 <= n <= 79]
        
 3. (n^2 + an + b), where |a| < 1000 and |b| <= 1000
 
 4. Find product of a & b for (n^2 + ab + b), where a & b
    consecutively produces max number of primes for n starting from 0 
*/

#include<iostream>
#include<cmath>
using namespace std;

bool isPrime(int x)
{
    if(x == 1) return false;
    if(x % 2 == 0 || x % 3 == 0) return false;
    for (int i = 5; i * i <= x; i+=2)
    {
        if(x % i == 0) return false;
    }
    return true;
}

int primeChainCount(int n, int a, int b)
{
    if(!isPrime(abs(n*n + a*n + b))) return 0; //Use abs(), isPrime doesn't work well with negative numbers
    return 1 + primeChainCount(n + 1, a, b);
}

int main()
{
    int longestPrimeChain = 0, answer = 0;
    for (int a = -999; a < 1000; a++)
    {
        for (int b = -1000; b <= 1000; b++)
        {
            int count = primeChainCount(0, a, b);
            if(count > longestPrimeChain)
            {
                longestPrimeChain = count;
                answer = a * b;
            }
        }
    }
    
    cout<<answer;    
    return 0;
}