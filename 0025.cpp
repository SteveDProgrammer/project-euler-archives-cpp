#include <iostream>
#include <algorithm>
using namespace std;

string Add(const string& s1, const string& s2)
{
    string result = "";
    size_t len1 = s1.length();
    size_t len2 = s2.length();
    size_t maxLength = max(len1, len2);
    
    int carry = 0;
    for (size_t i = 0; i < maxLength || carry > 0; ++i)
    {
        int digitSum = carry;
        if (i < len1) digitSum += s1[len1 - 1 - i] - '0';
        if (i < len2) digitSum += s2[len2 - 1 - i] - '0';
        
        result.push_back(digitSum % 10 + '0');
        carry = digitSum / 10;
    }

    // Reverse the string
    reverse(result.begin(), result.end());

    return result;
}

int main()
{
    string n1 = "1", n2 = "1", n3 = "";
    int counter = 2;

    while (n3.length() < 1000)
    {
        counter++;
        n3 = Add(n1, n2);
        n1 = n2;
        n2 = n3;
    }

    cout << counter << endl;
    return 0;
}
