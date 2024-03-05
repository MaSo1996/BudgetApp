#ifndef HEADER_3ED3A79810823A81
#define HEADER_3ED3A79810823A81

#include <iostream>

#include "UserManager.h"
#include "BudgetManager.h"
#include "DateMethods.h"

using namespace std;

class BudgetAppMain
{
    UserManager userManager;
    BudgetManager * budgetManager;
    DateMethods dateMethods;

    const string INCOMES_FILE_NAME;
    const string EXPANSES_FILE_NAME;

public:
    BudgetAppMain(string userFileName, string incomesFileName, string expanseFileName) :
        userManager(userFileName),
        INCOMES_FILE_NAME(incomesFileName),
        EXPANSES_FILE_NAME(expanseFileName)
    {
        budgetManager = NULL;
        loadUsersFromFile();
    }
    ~BudgetAppMain()
    {
        delete budgetManager;
        budgetManager = NULL;
    }

    void loadUsersFromFile();
    void userRegister();
    void userLogin();
    void userLogout();
    bool isUserLoggedIn();
    void addIncome();
    void addExpanse();
    void changeUserPassword();
    void showBalanceFromCurrentMonth();
    void showBalanceFromPreviousMonth();
    void showBalanceFromCustomPeriod();
};

#endif // header guard

