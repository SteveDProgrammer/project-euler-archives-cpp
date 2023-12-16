#include<iostream>

using namespace std;

int sumOfDivisors(int n)
{
    int total = 0;

    for (int i = 1; i <= n/2; i++)
    {
        if(n % i == 0)
        {
            total += i;
        }
    }
    
    return total;
}

int main()
{
    int sum = 0;
    
    for (int i = 1; i < 10000; i++)
    {
        int b = sumOfDivisors(i); // d(i)
        int a = sumOfDivisors(b); // d(b)
        
        //if a == i && a is not b
        if(a == i && a != b)
        {
            sum += i; // Adding a & b will add the pairs twice
        }
    }

    cout<<sum;
    return 0;
}