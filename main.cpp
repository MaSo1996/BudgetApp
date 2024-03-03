#include <iostream>

#include "UserManager.h"
#include "BudgetManager.h"
#include "AuxilaryMethods.h"

using namespace std;

int main()
{
    UserManager userManager("users.xml");
    BudgetManager * budgetManager = new BudgetManager(userManager.getLoggedUserId(),"incomes.xml","expanses.xml");
    //budgetManager.addOperation(INCOME);
    //budgetManager.loadOperationsFromFile(EXPANSE);
    //budgetManager.addOperation(EXPANSE);
    //budgetManager.showExpanses();
    userManager.loadUsers();
    userManager.userRegister();
    budgetManager->showIncomes();
}
