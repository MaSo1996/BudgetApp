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

public:
    BudgetAppMain(string userFileName) :
        userManager(userFileName)
    {
        budgetManager = NULL;
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
    void addIncome(Type type);
    void addExpanse(Type type);
    void changeUserPassword();
    void showBalanceFromCurrentMonth();
    void showBalanceFromPreviousMonth();
    void showBalanceFromCustomPeriod();
};

#endif // header guard

