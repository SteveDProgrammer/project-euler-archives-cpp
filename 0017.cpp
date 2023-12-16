#include<iostream>
using namespace std;

string digitName(int x)
{
    switch(x)
    {
        case 1: return "one" ;
        case 2: return "two";
        case 3: return "three";
        case 4: return "four";
        case 5: return "five";
        case 6: return "six";
        case 7: return "seven";
        case 8: return "eight";
        case 9: return "nine";
        case 10: return "ten";
        case 11: return "eleven";
        case 12: return "twelve";
        case 13: return "thirteen";
        case 14: return "fourteen";
        case 15: return "fifteen";
        case 16: return "sixteen";
        case 17: return "seventeen";
        case 18: return "eighteen";
        case 19: return "nineteen";
    }
    return "";
}

string tensName(int x)
{
    switch(x)
    {
        case 2: return "twenty";
        case 3: return "thirty";
        case 4: return "forty";
        case 5: return "fifty";
        case 6: return "sixty";
        case 7: return "seventy";
        case 8: return "eighty";
        case 9: return "ninety";
    }
    return "";
}

string generateString(int x)
{
    if (x < 20) return digitName(x);
    else if (x < 100) return (tensName(x / 10) + digitName(x % 10));
    else if (x < 1000)
    {
        if (x % 100 == 0) // Check if the number is a multiple of 100
            return digitName(x / 100) + "hundred";
        else
            return digitName(x / 100) + "hundredand" + generateString(x % 100);
    }
    else return "onethousand";
}

int main()
{
    string result = "";
    for (size_t i = 1; i <= 1000; i++)
    {
        result += generateString(i);
    }
    cout<<result.size();
    return 0;
}