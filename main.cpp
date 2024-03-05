#include <iostream>

#include "BudgetAppMain.h"
#include "AuxilaryMethods.h"
#include "Type.h"

using namespace std;

int main()
{
    char choice;

    BudgetAppMain budgetAppMain("users.xml","incomes.xml","expanses.xml");

    while(true)
    {
        if (!budgetAppMain.isUserLoggedIn())
        {
            choice = AuxilaryMethods::chooseFromMainMenu();

            switch(choice)
            {
            case '1':
                budgetAppMain.userRegister();
                break;
            case '2':
                budgetAppMain.userLogin();
                break;
            case '9':
                exit(0);
                break;
            }
        }
        else
        {
            choice = AuxilaryMethods::chooseFromUserMenu();

            switch(choice)
            {
            case '1':
                budgetAppMain.addIncome();
                break;
            case '2':
                budgetAppMain.addExpanse();
                break;
            case '3':
                budgetAppMain.showBalanceFromCurrentMonth();
                break;
            case '4':
                budgetAppMain.showBalanceFromPreviousMonth();
                break;
            case '5':
                budgetAppMain.showBalanceFromCustomPeriod();
                break;
            case '6':
                budgetAppMain.changeUserPassword();
                break;
            case '7':
                budgetAppMain.userLogout();
                break;
            case '9':
                exit(0);
            }
        }
    }
}
