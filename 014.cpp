#include<iostream>
using namespace std;

size_t iterateCollatz(size_t n)
{
    if(n == 1) return 1;
    if(n % 2 == 0) return iterateCollatz(n/2) + 1;
    if(n % 2 == 1) return iterateCollatz(3*n + 1) + 1;
}

int main()
{
    size_t longestChain = 0, answer = 0;
    for (size_t i = 999999; i > 0; i--)
    {
        size_t temp = iterateCollatz(i);
        if(temp > longestChain)
        {
            longestChain = temp;
            answer = i;
        }
    }
    cout<<answer;
    return 0;
}