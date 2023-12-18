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
#include<unordered_set>
using namespace std;

bool isAbundant(int n)
{
    int sum = 0;
    for(int i=1; i * i < n; i++)
    {
        if(n % i == 0)
        {
            sum += (i + n/i);
        }
    }
    //cout<<sum-n;
    if(sum-n > n) return true;
    return false;
}

int main()
{
    unordered_set<int> abundantNumbers;

    long long total = 28123*(28123 + 1)/2;

    for (int i = 12; i <= 28123; i++)
    {
        if(isAbundant(i))
        {
            abundantNumbers.insert(i);
        }   
    }

    cout<<abundantNumbers.size()<<endl;

    for(auto i = abundantNumbers.begin(); i!=abundantNumbers.end(); i++)
    {
        for (auto j = abundantNumbers.begin(); j != abundantNumbers.end(); j++)
        {
            if(!isAbundant(*i + *j))
            {
                total -= (*i + *j);
            }
        }
    }

    cout<<total;
    
    return 0;
}