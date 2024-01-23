#include <iostream>
#include <cmath>
#include <unordered_set>

using namespace std;

int main()
{
    unordered_set<int> numbers;
    for (int a = 2; a <= 100; a++)
    {
        for (int b = 2; b <= 100; b++)
        {
            /*
                - Multiplying 1e6 provides correct precision avoiding overflow. 
                
                - b*log(a) max value is 460 on conversion to int
                    - Then, b*log(a)*1e6 = 460,000,000
                    - In range of an int
                
                - Multiplying by >1e7 results 46,000,000,000 or more
                    - 4,600,000,000 > 2,147,483,647(MAX_INT)
                    - OVERFLOW!!!
            */
            numbers.insert(b*log(a) * 1e6);
        }
    }

    cout<<numbers.size();
    return 0;
}