#include <iostream>
#include<map>
using namespace std;

int findRecurringFactor(int d) {
    if (d % 2 == 0 || d % 5 == 0) {
        return 0;  // Numbers with 2 or 5 as factors have no finite recurring factor length
    }

    int remainder = 1;
    int i = 0;

    // Use a map to store remainders and their corresponding positions
    std::map<int, int> remainderPosition;

    while (true) {
        remainder = (remainder * 10) % d;
        i++;

        // If the remainder is 0, then there is no recurring cycle
        if (remainder == 0) {
            return 0;
        }

        // If the remainder is already in the map, then we have found a recurring cycle
        if (remainderPosition.find(remainder) != remainderPosition.end()) {
            return i - remainderPosition[remainder];
        }

        remainderPosition[remainder] = i;
    }
}


int main() {
    int longestRFL = 0, answer = 0; // longest recurring factor length
    for (int d = 999; d > 1; d--) {
        int currentRFL = findRecurringFactor(d);
        if(currentRFL > longestRFL)
        {   
            longestRFL = currentRFL;
            answer = d;
        }
    }
    cout << answer << endl;
    return 0;
}
