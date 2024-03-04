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

char AuxilaryMethods::chooseFromMainMenu()
{
    cin.sync();
    system("cls");

    cout << "MAIN MENU" << endl << "--- --- --- --- ---" << endl;
    cout << "1. Register new user" << endl;
    cout << "2. Login" << endl;
    cout << "9. Exit program" << endl;
    cout << "--- --- --- --- ---" << endl << endl;

    cout << "Choose option: ";

    return getChar();
}

char AuxilaryMethods::chooseFromUserMenu()
{
    cin.sync();
    system("cls");

    cout << "USER MENU" << endl << "--- --- --- --- ---" << endl;
    cout << "1. Add income" << endl;
    cout << "2. Add expanse" << endl;
    cout << "3. Show balance from current month" << endl;
    cout << "4. Show balance from previous month" << endl;
    cout << "5. Show balance from selected period" << endl;
    cout << "6. Change password" << endl;
    cout << "7. Log out" << endl;
    cout << "9. Exit program" << endl;
    cout << "--- --- --- --- ---" << endl << endl;

    cout << "Choose option: ";

    return getChar();
}


char AuxilaryMethods::getChar()
{
    string input = "";
    char character  = {0};

    while (true)
    {
        getline(cin, input);

        if (input.length() == 1)
        {
            character = input[0];
            break;
        }
        cout << "It's not a single character - try again" << endl;
    }
    return character;
}
