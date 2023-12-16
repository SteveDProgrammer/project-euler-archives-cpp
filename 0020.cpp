#include<iostream>
#include<cmath>
using namespace std;

string add2Numbers(string a, string b)
{
    string result = "";

    if(a.length() < b.length())
    {
        int diff = b.length() - a.length();
        a = string(diff, '0') + a;
    }
    else
    {
        int diff = a.length() - b.length();
        b = string(diff, '0') + b;
    }

    int carry = 0;

    for (int i = a.length()-1; i >= 0; i--)
    {
        int temp = (a[i] - '0') + (b[i] - '0') + carry;
        carry = temp/10;
        result = to_string(temp % 10) + result;
    }
    return result;
}

string Multiply(string num1, int num2)
{
    int num2_digits = log10(num2)+1;
    int carry = 0;
     
    string product[num2_digits] = "";
    string result = "";
 
    for (int i = 0; i < num2_digits; i++)
    {
        int digit = num2%10;
        for (int j = num1.size()-1; j >= 0; j--)
        {
            int temp = (num1[j] - '0') * digit + carry;
            carry = temp/10;
            if(j==0) product[i] = to_string(temp) + product[i];
            else product[i] = to_string(temp%10) + product[i];
        }
        product[i] = string(num2_digits-i-1, '0') + product[i] + string(i, '0'); // will sometimes have one or more digits compared
        carry = 0;                                                               // to other product[i] due to multi-digit carry
        num2 /= 10;
    }

    for (string x: product)
    {
        result = add2Numbers(x, result);
    }

    return result;    
} 

int main()
{
    int sum = 0;

    string factorial = "1";
    
    for (int i = 2; i <= 100; i++)
    {
        factorial = Multiply(factorial, i);
    }

    for(char x:factorial)
    {
        sum += (x-'0');
    }

    cout<<sum;
    return 0;
}