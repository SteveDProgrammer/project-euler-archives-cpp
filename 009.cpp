#include <iostream>
using namespace std;

int main()
{
    // a<b<c
    int tripletSum = 1000; // Because a<b<c cannot be satisfied for (a > 332) ---> 332<333<335
    for (int a = 1; a <= 332; a++)
    {
        for (int b = a+1; b < tripletSum-a-b; b++)
        {
            int c = tripletSum - a - b;
            if(a*a + b*b == c*c)
            {
                cout<<a*b*c;
                return 0;
            }
        }
    }
    return 0;
}