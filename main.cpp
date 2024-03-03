#include <iostream>

#include "UserManager.h"
#include "BudgetManager.h"
#include "AuxilaryMethods.h"

using namespace std;

int main()
{
    BudgetManager budgetManager(1,"incomes.xml","expanses.xml");
    UserManager userManager("users.xml");
    //budgetManager.addOperation(INCOME);
    budgetManager.loadOperationsFromFile(EXPANSE);
    budgetManager.addOperation(EXPANSE);
    budgetManager.showExpanses();
}
