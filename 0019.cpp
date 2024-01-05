#include<iostream>
using namespace std;

bool isLeapYear(int year) {
    return (year % 4 == 0 && (year % 100 != 0 && year % 400 == 0));
}

int daysInYear(int year)
{
    return 4*30 + 7*31 + ((isLeapYear(year)) ? 29 : 28);
}

int main()
{
    int firstDayOf1901 = daysInYear(1900)%7;
    int totalSundays = 0;

    int firstDayOfMonth = firstDayOf1901;

    for (int year = 1901; year <= 2000; year++)
    {  
        for(int month = 1; month <= 12; month++)
        {
            if(firstDayOfMonth%7 == 0) totalSundays++;
            if(month == 2) // Add 29 or 28 for next month
            {
                if(isLeapYear(year)) firstDayOfMonth += 29;
                else firstDayOfMonth += 28;
            }
            else if(month == 3 || month == 5 || month == 8 || month == 10) // Add 30 for next month
            {
                firstDayOfMonth += 30; 
            }
            else
            {
                firstDayOfMonth += 31;
            }
        }
    }

    cout<<totalSundays;
}