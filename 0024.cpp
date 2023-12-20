/*

If our number is 0123456789, and we want the millionth permutation, then 1000000/(n-1)! gives 2.75 ~ 2
which means we have 2.75 permutation cycles for (n-1) digits following digit at n position before we 
change the digit at position n
    - so for n = 0, we cycle the other digits (n-1)! times, then swap positions of 1 & 0
    - then for n = 1, we cycle 023456789 (n-1)! times, then swap positions of 1 & 2
    - then for n = 2, we cannot make a complete cycle because we need 2.75 permutations in total 
    - so we shift to (n-1) position and repeat the process

*** For permutations position always remains same only the digit keeps swapping positions

1. Calculate (n-1)!:
   - 9! = 362,880

2. Find the quotient and remainder:
   - 1000000 / 362880 = (~2.75) 2 with a remainder of 274240.

    2.1. First Iteration - Cycle through digits 1 to 9:
        - 2 complete cycles of permutations for digits 1 to 9, while keeping 0 fixed.
        - After each cycle, swap the leading digit with the next digit in the sequence.
        - After the 2nd cycle, the leading digit changes to 2.

    2.2. Second Iteration - Cycle through digits 0, 2 to 9:
        - 2 complete cycles of permutations for digits 0, 2, 3, 4, 5, 6, 7, 8, 9, while keeping 1 fixed.
        - After each cycle, swap the leading digit with the next digit in the sequence.
        - After the 2nd cycle, the leading digit changes to 3.

    2.3. Partial Third Iteration - Cycle through digits 0, 1, 3 to 9:
        - 0.75 * 362880 permutations for digits 0, 1, 3, 4, 5, 6, 7, 8, 9, while keeping 2 fixed.
        - After this partial cycle, the leading digit changes to 4.

3. Repeat:
   - Continue this process with the remaining digits 013456789 and the remainder 274240.
   - Calculate 274240 / 8! to find the next leading digit and position within the remaining digits.
   - Iterate until you've determined all digits in the permutation.
*/