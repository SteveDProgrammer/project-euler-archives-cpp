#include<iostream>
using namespace std;


int main()
{
    unsigned long long answer = 1;
    int n = 40;
    for (size_t k = 1; k <= 20; k++)
    {
        answer *= (n-k+1);
        answer /= k;
    }
    
    cout<<answer;

    return 0;
}