/*Sum of the squares of first ten natural numbers = 1^2 + 2^2 + ... + 10^2 = 385
Square of sum of the first 10 natural numbers = (1 + 2+...+10)^2 = 55^2 = 3025

Square of sum - Sum of squares: 3025 — 385 = 2640

Find the same for the first 100 natural numbers

HINT:

Sum of n numbers: n(n+1)/2
Sum of squares of n natural numbers: [n(n+1)(2n+1)]/6
Sum of squares of first n even numbers: [2n(n + 1)(2n + 1)]/3
Sum of squares of first n odd numbers: [n(2n+1)(2n-1)]/3
*/

#include<iostream>
using namespace std;

int main()
{
    int n = 100;
    int sum_of_squares = n*(n+1)*(2*n+1)/6;
    int square_of_sum = n*(n+1)/2 * n*(n+1)/2;
    cout<< square_of_sum - sum_of_squares;
    return 0;
}