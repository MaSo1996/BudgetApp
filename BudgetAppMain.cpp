#include "BudgetAppMain.h"

using namespace std;

void BudgetAppMain::loadUsersFromFile()
{
    userManager.loadUsers();
}

void BudgetAppMain::userRegister()
{
    userManager.userRegister();
}

void BudgetAppMain::userLogin()
{
    userManager.loginUser();

    if (isUserLoggedIn())
    {
        budgetManager = new BudgetManager(userManager.getLoggedUserId(),"incomes.xml","expanses.xml");
    }
}

void BudgetAppMain::userLogout()
{
    userManager.logOutUser();
    delete budgetManager;
    budgetManager = NULL;
}

bool BudgetAppMain::isUserLoggedIn()
{
    if (userManager.getLoggedUserId() != 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void BudgetAppMain::addIncome(Type type)
{
    budgetManager->addOperation(type);
}

void BudgetAppMain::addExpanse(Type type)
{
    budgetManager->addOperation(type);
}

void BudgetAppMain::changeUserPassword()
{
    userManager.changeUserPassword();
}

void BudgetAppMain::showBalanceFromCurrentMonth()
{
    budgetManager->showBalanceFromChosenPeriod(dateMethods.getFirstDayOfCurrentMonth(),dateMethods.getCurrentDate());
}

void BudgetAppMain::showBalanceFromPreviousMonth()
{
    budgetManager->showBalanceFromChosenPeriod(dateMethods.getFirstDayOfLastMonth(),dateMethods.getLastDayOfLastMonth());
}

void BudgetAppMain::showBalanceFromCustomPeriod()
{
    string firstDate, secondDate;

    cout << "Type first date in format yyyy-mm-dd: ";
    firstDate = AuxilaryMethods::readLine();

    cout << "Type second date in format yyyy-mm-dd: ";
    secondDate = AuxilaryMethods::readLine();

    budgetManager->showBalanceFromChosenPeriod(firstDate,secondDate);
}
