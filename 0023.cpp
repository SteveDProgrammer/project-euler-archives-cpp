/*
- Perfect number -> Sum of divisors = number
- Deficient      -> Sum of divisors < number
- Abundant       -> Sum of divisors > number
- 12 -> Smallest abundant number
- 24 -> Smallest number that can be represented 
        as the sum of two abundant numbers 
- integer > 28123 -> always a sum of two abundant numbers

Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.
*/

#include<iostream>
#include<bitset>
using namespace std;

const int limit = 28123;

bool isAbundant(int n)
{
    int sum = 0;
    for (int i = 2; i * i <= n; i++) // Start from 2 beacuse adding n/1 would include n in the sum
    {
        if (n % i == 0)
        {
            if(i * i == n) // Don't add n/i for perfect squares to avoid double addition of square root
            {
                sum += i;
                continue;    
            }
            sum += (i + n/i);
        }
    }
    return sum > n;
}

int main()
{
    bitset<limit + 1> isAbundantNum;
    bitset<limit + 1> isSumOfAbundant;
    int total = 0;

    for (int i = 12; i <= limit; i++)
    {
        if (isAbundant(i))
        {
            isAbundantNum.set(i);
        }
    }

    for (int i = 12; i <= limit; i++)
    {
        if (isAbundantNum.test(i))
        {
            for (int j = i; i + j <= limit; j++)
            {
                if (isAbundantNum.test(j))
                {
                    isSumOfAbundant.set(i + j);
                }
            }
        }
    }

    for (int i = 1; i <= limit; i++)
    {
        if (!isSumOfAbundant.test(i))
        {
            total += i;
        }
    }

    cout << total;

    return 0;
}