#include <iostream>
#include <cmath>
using namespace std;

string Add(string s1, string s2)
{
    string result = "";
    int lenDiff = abs((int)s1.length() - (int)s2.length());

    if(s1.length() > s2.length()) 
    {
        s2 = string(lenDiff, '0') + s2;
    }
    else if(s1.length() < s2.length()) 
    {
        s1 = string(lenDiff, '0') + s1;
    }

    int digit = 0, carry = 0;
    for(int i = s1.length() - 1; i >= 0; i--)
    {
        int digitSum = (s1[i] - '0') + (s2[i] - '0') + carry; // convert char to int
        digit = digitSum % 10;
        result.insert(result.begin(), digit + '0'); // convert int to char
        carry = digitSum / 10;
    }

    if(carry > 0) result.insert(result.begin(), carry + '0');
    return result;
}

int main()
{
    string n1 = "1", n2 = "1", n3 = "";
    int counter = 2;
    while(n3.length() < 1000)
    {
        counter++;
        n3 = Add(n1, n2);
        n1 = n2;
        n2 = n3;
    }
    cout<<counter;
    return 0;
}
