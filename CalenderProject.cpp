#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

const int DAYS_IN_WEEK = 7;
const int MONTHS_IN_YEAR = 12;

int get_first_day_of_year(int year)
{
    int day;
    day = (((year - 1) * 365) + ((year - 1) / 4) - ((year - 1) / 100) + ((year) / 400) + 1) % DAYS_IN_WEEK;
    return day;
}

int main()
{
    int year, month, day, daysInMonth, weekDay = 0, startingDay;
    cout << "Enter Year:";
    cin >> year;

    string months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int monthDay[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        monthDay[1] = 29;

    startingDay = get_first_day_of_year(year);

    for (month = 0; month < MONTHS_IN_YEAR; month++)
    {
        daysInMonth = monthDay[month];
        cout << "\n\n---------------" << months[month] << "-------------------\n";
        cout << "\n  Sun  Mon  Tue  Wed  Thurs  Fri  Sat\n";

        for (weekDay = 0; weekDay < startingDay; weekDay++)
            cout << "     ";

        for (day = 1; day <= daysInMonth; day++)
        {
            cout << setw(5) << day;

            if (++weekDay >= DAYS_IN_WEEK)
            {
                cout << "\n";
                weekDay = 0;
            }
        }

        startingDay = weekDay;
    }

    // Create a 2D string array to store tasks for each day
    string tasks[12][31]; // Assuming max 31 days for simplicity

    // Ask the user if they want to input tasks for each month
    char input;
    for (month = 0; month < MONTHS_IN_YEAR; month++)
    {
        cout << "\nDo you want to input tasks for " << months[month] << "? (Y/N): ";
        cin >> input;

        if (input == 'Y' || input == 'y')
        {
            cout << "Enter the date (1-" << monthDay[month] << ") for the task in " << months[month] << ": ";
            cin >> day;

            if (day >= 1 && day <= monthDay[month])
            {
                cout << "Enter task for " << months[month] << " " << day << ": ";
                cin.ignore(); // Clear newline from previous input
                getline(cin, tasks[month][day - 1]);
            }
            else
            {
                cout << "Invalid date. Task not added.\n";
            }
        }
    }

    // Display tasks
    cout << "\n\n--------------- Tasks -------------------\n";
    for (month = 0; month < MONTHS_IN_YEAR; month++)
    {
        daysInMonth = monthDay[month];
        cout << "\n" << months[month] << ":\n";

        for (day = 1; day <= daysInMonth; day++)
        {
            if (!tasks[month][day - 1].empty())
            {
                cout << months[month] << " " << day << ": " << tasks[month][day - 1] << "\n";
            }
        }
    }

    return 0;
}
