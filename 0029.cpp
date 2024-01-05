#include <iostream>
#include <cmath>
#include <unordered_set>

using namespace std;

int main()
{
    unordered_set<long int> numbers;
    for (int a = 2; a <= 100; a++)
    {
        for (int b = 2; b <= 100; b++)
        {
            numbers.insert(b*log(a) * 1e6);
        }
    }
    
    cout<<numbers.size();
    return 0;
}