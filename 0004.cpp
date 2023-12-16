/*
Largest Palindrome Product
Problem 4

A palindromic number reads the same both ways. 
The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 x 99.
Find the largest palindrome made from the product of two 3-digit numbers.

HINT:

Consider a positive integer "n" with "d" digits. 
The smallest "d" digit number is 10^(d-1), and the largest "d" digit number is (10^d) - 1.

EXAMPLE: d = 4 => 10^(d-1) = 1000 => (10^d) - 1 = 9999

Therefore, 10^(d-1) <= n < 10^d
           => log10(10^(d-1)) <= log10(n) < log10(10^d)
           => d - 1 <= log10(n) < d
           => d <= log10(n) + 1 < d + 1 --- Adding 1 to each sides

            log10(n) + 1 is a real number that falls between two consecutive integers "d" and "d + 1."
            
            So, d = log10(n) + 1
*/

#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(int number){
    //int back = (int)log10(number);
    string num_string = to_string(number);

    int front = 0;
    int back = num_string.length()-1;

    while(front < back)
    {
        if(num_string[front]!=num_string[back]) return false;
        front++;
        back--;
    }
    return true;
}

int main()
{
    int largestPalindrome = 0;
    for(int i = 999; i > 100; i--)
        for(int j = 999; j > 100; j--)
        {
            if(isPalindrome(i * j)) 
            {
                if(largestPalindrome < i * j) largestPalindrome = i * j;
                else break;
            }
        }

    cout<<largestPalindrome;
    return 0;
}