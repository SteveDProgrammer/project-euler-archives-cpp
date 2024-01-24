/*
To find the millionth permutation of "0123456789":

1. Calculate (n-1)!:
   - (9!) = 362,880

2. Find the quotient (q) and remainder (r) after dividing 1,000,000 by (n-1)!:
   - 1,000,000 / 362,880 = 2 with a remainder of 274,240.

3. Iterations:

    3.1. First Iteration - Cycle through digits 1 to 9:
        - 2 cycles of permutations for digits 1 to 9 while keeping value at position 0 fixed.
        - After each cycle, swap the leading digit with the next digit in the sequence.
        - After the second cycle, the leading digit becomes 2.

    3.2. Second Iteration - Cycle through digits 0, 1, 3, 4, 5, 6, 7, 8, 9:
        - 2 cycles of permutations for digits 0, 1, 3, 4, 5, 6, 7, 8, 9 while keeping the value at position 0 fixed.
        - After each cycle, swap the leading digit with the next digit in the sequence.
        - After the second cycle, the leading digit becomes 4.

    3.3. Partial Third Iteration - Cycle through digits 0, 1, 3 to 9:
        - 0.75 * 362,880 permutations for digits 0, 1, 3, 4, 5, 6, 7, 8, 9, keeping 2 fixed.
        - After this partial cycle, the leading digit becomes 4.

4. Repeat:
   - Continue the process with the remaining digits (013456789) and the remainder (r = 274,240).
   - Calculate r / (8!) to find the next leading digit and its position within the remaining digits.
   - Iterate until all digits in the permutation are determined.
*/

#include <iostream>
using namespace std;

int factorial(int x) {
    if (x == 0) return 1;
    return x * factorial(x - 1);
}

void permute(string &arrangement, int n, int fixedPos = 0, int r = 999999) { // millionth permutation is reached after 999999th iteration
    if (r == 0) return; // r represents the number of permutations remaining

    int q = r / factorial(n - 1); // Quotient
    r = r % factorial(n - 1);    // Remainder

    cout<<arrangement<<" | Fixed Pos: "<<fixedPos<<" | Relative q: "<<q<<endl;
    for (int j = fixedPos + 1; j <= fixedPos + q; j++) {
        for (int i = 0; i < j; i++)
        {
            cout<<"-";
        }
        swap(arrangement[fixedPos], arrangement[j]);
        cout<<arrangement.substr(j, arrangement.length()-j)<<endl;
    }

    cout<<endl;

    permute(arrangement, --n, ++fixedPos, r);
}

int main() {
    string arrangement = "0123456789";
    int n = arrangement.length();

    permute(arrangement, n);

    cout << arrangement;
    return 0;
}
