#include <iostream>
using namespace std;

long int findRecurringFactor(long int d) {
    if (d % 2 == 0 || d % 5 == 0) {
        return 0;  // Numbers with 2 or 5 as factors have no finite recurring factor length
    }

    long int i = 1;
    long int pow = 10;
    while ((pow - 1) % d != 0) {
        i++;
        pow *= 10;
        if (i > LONG_MAX) {  // Break the loop if it runs for too long
            return -1;
        }
    }
    return i;
}

int main() {
    long int longestRFL = 0, answer = 0; // longest recurring factor length
    for (long int d = 999; d > 1; d--) {
        if(findRecurringFactor(d) > longestRFL)
        {   
            longestRFL = findRecurringFactor(d);
            answer = d;
            cout<<d<<endl;
        }
    }
    cout << answer << endl;
    return 0;
}
