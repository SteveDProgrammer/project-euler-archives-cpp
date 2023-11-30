#include<iostream>
using namespace std;

bool isPrime(int num) {
    if (num < 2) {
        return false;
    }
    if(num % 3 == 0) return false;
    for (int i = 3; i * i <= num; i+=2) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main()
{
    long long sum = 2 + 3;
    for (int i = 5; i < 2000000; i+=2) //even numbers will be skipped
    {
        if(isPrime(i)) sum += i;
    }
    cout<<sum;
    return 0;
}