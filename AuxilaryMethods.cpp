#include "AuxilaryMethods.h"

using namespace std;

string AuxilaryMethods::readLine()
{
    string phrase;
    getline(cin,phrase);
    return phrase;
}

double AuxilaryMethods::readAmount()
{
    string amount;
    getline(cin,amount);
    if (amount.find(',') != -1)
    {
        amount.replace(amount.find(','),1,".");
    }

    return stod(amount);
}
