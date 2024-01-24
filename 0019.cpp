#include<iostream>
using namespace std;

bool isLeapYear(int year) 
{
    return (year % 4 == 0 && (year % 100 != 0 && year % 400 == 0));
}

int daysInYear(int year)
{
    return 4*30 + 7*31 + ((isLeapYear(year)) ? 29 : 28);
}

int main()
{
    int firstDayOf1901 = daysInYear(1900)%7 + 1; //daysInYear(int)%7 is last day of year, add one for next day (first day of next year)
    int totalSundays = 0;

    int currDay = firstDayOf1901;

    for (int year = 1901; year <= 2000; year++)
    {  
        for(int month = 0; month < 12; month++) // Total of twelve months
        {
            if(currDay%7 == 0) totalSundays++;
            if(month < 1) // Only 1 February
            {
                currDay += 28;
                if(isLeapYear(year)) currDay += 1;
            }
            else if(month < 5) currDay += 30; // Only (5-1 = 4) 30 day months
            else currDay += 31; // The rest are all 31 day months
        }
    }

    cout<<totalSundays;
}