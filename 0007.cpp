#include <iostream>
using namespace std;

bool isPrime(int num) {
    if (num < 2) {
        return false;
    }
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int findPrime(int index) {
    int count = 0;
    int num = 2;
    while (true) {
        if (isPrime(num)) {
            count += 1;
            if (count == index) {
                return num;
            }
        }
        num += 1;
    }
}

int main() {
    // Find the 10,001st prime number
    int result = findPrime(10001);
    cout << result << endl;
    return 0;
}
