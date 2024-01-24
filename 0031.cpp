#include<iostream>

using namespace std;

int coins[8] = {1, 2, 5, 10, 20, 50, 100, 200};

int DFS(int amount, int coinIndex)
{
    if(amount < 0)
        return 0;

    if(amount == 0)
        return 1;

    int totalWays = 0;

    /*
        We iterate in range (coinIndex, 8) to avoid counting the same set of coins multiple times in different order.

        E.g, coins = {1, 2}, and we want make an amount of 3

        If we start with 1, we have following possibilities:
            
            - Use 3 coins of 1 (1+1+1)
            - Use 1 coin of 1 & one coin of 2 (1+2)
        
        Then, if we start with 2, we have following possibilities:
            
            - Use 1 coin of 2 & one coin of 1 (2+1)
    */

    for (int i = coinIndex; i < 8; i++)
    {
        totalWays += DFS(amount-coins[i], i);
    }

    return totalWays;
}

int main()
{
    int amount = 200;
    cout<<DFS(amount, 0);
    return 0;
}


