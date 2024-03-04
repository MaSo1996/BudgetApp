#ifndef HEADER_EA15FBA543579842
#define HEADER_EA15FBA543579842

#include <iostream>
#include <sstream>
#include <map>
#include <ctime>
#include "AuxilaryMethods.h"

using namespace std;

class DateMethods
{
public:
    string getDate();
    int convertDateStringToInt(string date);
    int returnNumberOfDaysInMonth(string year, string month);
    string getFirstDayOfCurrentMonth();
    string getLastDayOfCurrentMonth();
    bool validateDate(string date);
    string getCurrentDate();
    string getFirstDayOfLastMonth();
    string getLastDayOfLastMonth();
};
#endif // header guard

