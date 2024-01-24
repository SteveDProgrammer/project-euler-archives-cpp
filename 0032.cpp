#include<iostream>
#include<cmath>
#include<unordered_set>
using namespace std;

const int limit = 987654321;

bool isPandigital(int multiplicand, int multiplier)
{
    int product = 0;
    if(multiplicand <= limit/multiplier) // to avoid overflow
    {
        product = multiplicand * multiplier;
    }
    else // if overflow return false
    {
        return false;
    }

    int digits = (int)log10(product) + (int)log10(multiplicand) + (int)log10(multiplier) + 3;
    if(digits != 9 ) return false; // can't be Pandigital if not exactly 9 digits

    if(multiplicand % 10 == 0 || multiplier % 10 == 0 || product % 10 == 0) // can't be pandigital if there's a zero
    {
        return false;
    }

    unordered_set<int> digitTracker;

    while(multiplicand != 0)
    {
        digitTracker.insert(multiplicand % 10);
        multiplicand /= 10;
    }

    while(multiplier != 0)
    {
        digitTracker.insert(multiplier % 10);
        multiplier /= 10;
    }
    
    while(product != 0)
    {
        digitTracker.insert(product % 10);
        product /= 10;
    }

    if(digitTracker.size() == 9)
    {
        return true;
    }
    return false;
}

int main()
{
    unordered_set<int> products;
    int sum = 0;
    
    for (int i = 1; i <= limit; i++)
    {
        for (int j = limit/i; j >= i+1; j--)
        {
            if(isPandigital(i, j))
            {
                products.insert(i * j);
            }
        }
    }

    for(int x: products)
    {
        sum+=x;
    }

    cout<<sum;

    return 0;
}