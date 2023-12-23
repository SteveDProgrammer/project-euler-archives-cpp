#include<iostream>
using namespace std;

int main()
{
    int answer = 1;
    int multiplier = 1;
    for (int i = 3; i <= 1001; i+=2)
    {
        int sqr = i*i;
        for (int j = 0; j < 4; j++)
        {
            answer += sqr;
            sqr -= (2*multiplier);
        }
        multiplier++;
    }
    cout<<answer;
    return 0;
}