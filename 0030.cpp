#include<iostream>
#include<climits>
#include<cmath>

using namespace std;

int findPowerSum(int x)
{
    int sum = 0;
    while (x != 0)
    {
        int digit = x % 10;
        sum += (digit * digit * digit * digit * digit);
        x /= 10;
    }
    
    return sum;
}

int main()
{
    int answer = 0;

    for (int i = 11; i < 1000000; i++)
    {
        if(i == findPowerSum(i))
        {
            answer += i;
        }
    }
    cout<<answer;

    return 0;
}