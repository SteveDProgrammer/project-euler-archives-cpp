#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> largeNum = {1};
    int answer = 0;

    for (size_t i = 1; i <= 1000; i++)
    {
        int carry = 0, temp = 0;
        for(auto it = largeNum.rbegin(); it !=largeNum.rend(); it++)
        {
            temp = ((*it)*2+carry) % 10;
            carry = ((*it)*2+carry)/10;
            *it = temp;
        }

        while(carry != 0)
        {
            largeNum.insert(largeNum.begin(),carry%10);
            carry = carry/10;
        }
    }
    
    for (int x:largeNum)
    {
        //cout<<x;
        answer += x;
    }

    cout<<answer;
    
    

    return 0;
}