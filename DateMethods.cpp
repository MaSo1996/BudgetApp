#include "DateMethods.h"

using namespace std;

string DateMethods::getDate()
{
    cin.sync();

    cout << "Type date of operation in format yyyy-mm-dd: ";

    string year, month, day, phrase;

    getline(cin,phrase,'-');
    year = phrase;
    getline(cin,phrase,'-');
    month = phrase;
    getline(cin,phrase);
    day = phrase;

    if (!validateDate(year,month,day))
    {
        cout << "Incorrect date";
        exit(0);
    }

    return (year + "-" + month + "-" + day);
}

int DateMethods::convertDateStringToInt(string date)
{
    cin.sync();

    stringstream ss(date);
    string year, month, day, phrase;

    getline(ss,phrase,'-');
    year = phrase;
    getline(ss,phrase,'-');
    month = phrase;
    getline(ss,phrase);
    day = phrase;

    return stoi(year + month + day);
}

int DateMethods::returnNumberOfDaysInMonth(string year, string month)
{
    map <int,int> daysOfMonths;

    daysOfMonths[1] = 31;
    daysOfMonths[3] = 31;
    daysOfMonths[4] = 30;
    daysOfMonths[5] = 31;
    daysOfMonths[6] = 30;
    daysOfMonths[7] = 31;
    daysOfMonths[8] = 31;
    daysOfMonths[9] = 30;
    daysOfMonths[10] = 31;
    daysOfMonths[11] = 30;
    daysOfMonths[12] = 31;

    if ((stoi(year) % 4 == 0 && stoi(year) % 100 != 0) || (stoi(year) % 400 == 0))
    {
        daysOfMonths[2] = 29;
    }
    else
    {
        daysOfMonths[2] = 28;
    }

    return daysOfMonths[stoi(month)];
}

string DateMethods::getLastDayOfCurrentMonth()
{
    cin.sync();

    stringstream ss(getCurrentDate());
    string year, month, day, phrase;

    getline(ss,phrase,'-');
    year = phrase;
    getline(ss,phrase,'-');
    month = phrase;
    day = to_string(returnNumberOfDaysInMonth(year,month));

    return (year + "-" + month + "-" + day);
}

bool DateMethods::validateDate(string year, string month, string day)
{
    int dateAsInt = stoi(year + month + day);

    int numberOfDaysInMonth = returnNumberOfDaysInMonth(year, month);

    int lastDayOfMonthAsInt = convertDateStringToInt(getLastDayOfCurrentMonth());

    if (year.length() == 4 && (month.length() == 2) && stoi(month) <= 12 && (day.length() == 2) && stoi(day) <= numberOfDaysInMonth && dateAsInt <= lastDayOfMonthAsInt)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

string DateMethods::getCurrentDate()
{
    time_t now = time(0);
    struct tm * timeAsStruct;
    timeAsStruct = localtime(& now);

    string year, month, day;

    year = to_string(timeAsStruct->tm_year + 1900);

    month = to_string(timeAsStruct->tm_mon + 1);

    if (month.length() == 1)
    {
        month = "0" + month;
    }

    day = to_string(timeAsStruct->tm_mday);

    if (day.length() == 1)
    {
        day = "0" + day;
    }

    return year + "-" + month + "-" + day;
}

string DateMethods::getLastMonthLastDay()
{
    cin.sync();

    stringstream ss(getCurrentDate());
    string phrase, month;
    int year, day, monthAsInt;

    getline(ss,phrase,'-');
    year = stoi(phrase);
    getline(ss,phrase,'-');
    month = phrase;
    monthAsInt = stoi(month);
    getline(ss,phrase);
    day = stoi(phrase);

    if (month == "01")
    {
        year =- 1;
        month = "12";
        day = returnNumberOfDaysInMonth(to_string(year), month);

        return (to_string(year) + "-" + month + "-" + to_string(day));
    }
    else
    {
        monthAsInt -= 1;
        month = to_string(monthAsInt);
        if (month.length() == 1)
        {
            month = "0" + month;
        }
        day = returnNumberOfDaysInMonth(to_string(year), month);

        return (to_string(year) + "-" + month + "-" + to_string(day));
    }
}

string DateMethods::getLastMonthFirstDay()
{
    cin.sync();

    stringstream ss(getCurrentDate());
    string phrase, month, day;
    int year, monthAsInt;

    getline(ss,phrase,'-');
    year = stoi(phrase);
    getline(ss,phrase,'-');
    month = phrase;
    monthAsInt = stoi(month);
    getline(ss,phrase);
    day = phrase;

    if (month == "01")
    {
        year =- 1;
        month = "12";
        day = "01";

        return (to_string(year) + "-" + month + "-" + day);
    }
    else
    {
        monthAsInt -= 1;
        month = to_string(monthAsInt);
        if (month.length() == 1)
        {
            month = "0" + month;
        }
        day = "01";

        return (to_string(year) + "-" + month + "-" + day);
    }
}
