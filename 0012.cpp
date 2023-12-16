#include<iostream>
using namespace std;

int divisorCount(int x)
{
    if(x == 1) return 1;

    int count = 1;
    
    for (int i = 1; i * i <= x; i++)
    {
        if(x%i==0)
        {
            count++;
        }
    }
    return count*2;
}

int main()
{
    int n = 1;

    while(divisorCount(n*(n+1)/2)<=500)
    {
        n++;
    }
    cout<<n*(n+1)/2;
    return 0;
}