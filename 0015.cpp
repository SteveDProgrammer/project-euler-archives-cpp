#include<iostream>
using namespace std;


int main()
{
    unsigned long long answer = 1;
    int n = 40;
    for (size_t k = 1; k <= 20; k++)
    {
        /*
            Because formula is c(n,k) = n!/(n-k)!*k!
                                n!/(n-k)! -> n * (n-1) * ... * (n-k)!/(n-k)!
        */
        answer *= (n-k+1); //goes from 40 to 21
        answer /= k;
    }
    
    cout<<answer;

    return 0;
}